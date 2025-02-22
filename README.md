# ROS2 Joystick Listener

This repository contains a ROS2 package that subscribes to joystick inputs and publishes corresponding velocity commands to the `/cmd_vel` topic.

## Prerequisites

Before using this package, you need to install ROS2. Please follow the official ROS2 installation guide:
[ROS2 Installation Guide](https://docs.ros.org/en/)

## Required Packages

Ensure that you have the necessary ROS2 packages installed before running this repository. You can install them using the following commands:

```sh
sudo apt update
sudo apt install ros-humble-joy  # Change 'humble' to your ROS2 distribution name if different
```

## Checking Joystick Detection

Before running the package, verify that your joystick is detected by your system.

### Check if the system detects your joystick:

```sh
ls /dev/input/
```

Look for a device like `js0` (e.g., `/dev/input/js0`). If not detected, try reconnecting your joystick or installing necessary drivers.

### Test joystick inputs:

```sh
jstest /dev/input/js0
```

If the `jstest` command is not found, install `joystick` utilities:

```sh
sudo apt install joystick
```

## Building the Package

Navigate to your ROS2 workspace and clone this repository:

```sh
cd ~/ros2_ws/src
git clone https://github.com/Mehmetmrtgl/ros2_joystick.git
```

Then, build the package:

```sh
cd ~/ros2_ws
colcon build --packages-select joy_listener_cpp
source install/setup.bash
```

## Running the Nodes

To launch the system and start listening to joystick inputs, run:

```sh
ros2 launch joy_listener_cpp start_system.launch.py
```

This will start:
- `joy_node`: Reads joystick inputs and publishes them to the `/joy` topic.
- `joy_listener`: Subscribes to `/joy` and publishes velocity commands to `/cmd_vel`.

## Testing the Output

To check if velocity commands are being published, open a new terminal and run:

```sh
ros2 topic echo /cmd_vel
```

You should see messages updating when you move the joystick.

## Troubleshooting

- If `joy_node` does not publish messages, ensure that your joystick is properly detected and `jstest` works.
- If `cmd_vel` messages are not appearing, check that `joy_listener` is running.
- Source the workspace if required: `source install/setup.bash`

## Contribution

Feel free to open issues or submit pull requests if you find any bugs or want to improve this repository.



