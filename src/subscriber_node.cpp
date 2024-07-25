#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3_stamped.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "geometry_msgs/msg/twist.hpp"

class SubscriberNode : public rclcpp::Node {
public:
    SubscriberNode()
    : Node("subscriber") {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        gps_controller_subscriber_ = this->create_subscription<geometry_msgs::msg::Vector3Stamped>(
            "/gps_controller/vel", 10, std::bind(&SubscriberNode::gps_callback, this, std::placeholders::_1));
        gps_subscriber_ = this->create_subscription<sensor_msgs::msg::NavSatFix>(
            "/gps", 10, std::bind(&SubscriberNode::gps2_callback, this, std::placeholders::_1));
        dist_subscriber_ = this->create_subscription<sensor_msgs::msg::Range>(
            "/distance/pr", 10, std::bind(&SubscriberNode::dist_callback, this, std::placeholders::_1));
        dist2_subscriber_ = this->create_subscription<sensor_msgs::msg::Range>(
             "/distance/pr2", 10, std::bind(&SubscriberNode::dist2_callback, this, std::placeholders::_1));
    }

private:
    void gps_callback(const geometry_msgs::msg::Vector3Stamped::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Vector: [%f, %f, %f]", msg->vector.x, msg->vector.y, msg->vector.z);
    }

    void gps2_callback(const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "NavSatFix: [latitude: %f, longitude: %f, altitude: %f]", msg->latitude, msg->longitude, msg->altitude);
    }

    void dist_callback(const sensor_msgs::msg::Range::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Sensor 1 > Distance from obstacle: %f", msg->range);
    }

    void dist2_callback(const sensor_msgs::msg::Range::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Sensor 2 > Distance from obstacle: %f", msg->range);
    }
    


    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3Stamped>::SharedPtr gps_controller_subscriber_;
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr gps_subscriber_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr dist_subscriber_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr dist2_subscriber_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubscriberNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
