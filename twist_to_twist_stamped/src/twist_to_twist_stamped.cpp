#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"

class TwistToTwistStamped : public rclcpp::Node
{
public:
  TwistToTwistStamped() : Node("twist_to_twist_stamped")
  {
    twist_subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel", 10,
      std::bind(&TwistToTwistStamped::twist_callback, this, std::placeholders::_1));
    
    twist_stamped_publisher_ = this->create_publisher<geometry_msgs::msg::TwistStamped>("/diff_cont/cmd_vel", 10);
  }

private:
  void twist_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
    auto twist_stamped_msg = geometry_msgs::msg::TwistStamped();
    twist_stamped_msg.header.stamp = this->now();
    twist_stamped_msg.twist = *msg;

    twist_stamped_publisher_->publish(twist_stamped_msg);
  }

  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr twist_subscriber_;
  rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr twist_stamped_publisher_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TwistToTwistStamped>());
  rclcpp::shutdown();
  return 0;
}
