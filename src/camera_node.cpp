#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"


class CamNode : public rclcpp::Node {
public:
    CamNode()
    : Node("camera_node") {
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
            "/camera/image_raw", 10, std::bind(&CamNode::image_callback, this, std::placeholders::_1));
    }

private:
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
        try{
            cv::Mat frame = cv_bridge::toCvShare(msg,"bgr8")->image;
            cv::imshow("Camera",frame);
            cv::waitKey(10);
        }
        catch(cv_bridge::Exception& e){
            RCLCPP_ERROR(this->get_logger(),"cv_bridge exception %s",e.what());
        }
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CamNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
