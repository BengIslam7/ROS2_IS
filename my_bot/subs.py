#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3Stamped
from sensor_msgs.msg import NavSatFix
from sensor_msgs.msg import Range
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Image
from sensor_msgs.msg import LaserScan

class SubscriberNode(Node):
    
    def __init__(self):
        super().__init__("subscriber")
        self.publisher_ = self.create_publisher(Twist,"/cmd_vel",10)
        self.gps_controller_subscriber = self.create_subscription(Vector3Stamped,"/gps_controller/vel",self.gps_callback,10) # from gps
        self.gps_subscriber = self.create_subscription(NavSatFix,"/gps",self.gps2_callback,10) # from gps
        self.dist_subscriber = self.create_subscription(Range,"/distance/pr",self.dist_callback,10) # from ultrasonic sensor
        self.dist2_subscriber = self.create_subscription(Range,"/distance/pr2",self.dist2_callback,10) # from ultrasonic sensor

    def gps_callback(self,msg:Vector3Stamped):
        self.get_logger().info(str(msg.vector))    
        
    def gps2_callback(self,msg:NavSatFix):
        self.get_logger().info(str(msg))

    def dist_callback(self,msg:Range):
        self.get_logger().info("Sensor 1 > Distance from obstacle : "+str(msg.range))
        cmd = Twist()
        if msg.range<=0.5 :
            print("Avoiding Obstacle")
            pass

    def dist2_callback(self,msg:Range):
        self.get_logger().info("Sensor 2 > Distance from obstacle : "+str(msg.range))
        cmd = Twist()
        if msg.range<=0.5 :
            print("Avoiding Obstacle")
            pass
    

def main(args=None):
    rclpy.init(args=args)
    node = SubscriberNode()
    rclpy.spin(node)
    rclpy.shutdown()
