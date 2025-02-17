#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "geometry_msgs/msg/twist.hpp"

class JoyListener : public rclcpp::Node
{
public:
    JoyListener() : Node("joy_listener")
    {
        // Joy topic'ine abone ol
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "joy", 10, std::bind(&JoyListener::listener_callback, this, std::placeholders::_1)
        );

        // cmd_vel topic'ine yayın yapmak için publisher oluştur
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        RCLCPP_INFO(this->get_logger(), "Joystick dinlemeye başlandı.");
    }

private:
    void listener_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
    {
        // Gelen joystick hareketlerine göre cmd_vel mesajı oluştur
        auto message = geometry_msgs::msg::Twist();

        // Sağ joystick X ekseninden (axes[2]) hareket komutu gönder
        message.linear.x = msg->axes[1];  // Right joystick X ekseni
        message.angular.z = msg->axes[2];
        // cmd_vel topic'ine mesaj gönder
        publisher_->publish(message);
    }

    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JoyListener>());
    rclcpp::shutdown();
    return 0;
}
