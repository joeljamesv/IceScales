**#Devices**

When a device gets connected, it exposes higher level attributes under /sys and lower level attributes with which we can send bytes, receive bytes are
exposed under /dev 

Since this do not have a actual hardware, creating a /sys makes sense, /dev is skipped. /sys gives different views to approach the device, 
1. **Bus view** - where the device is connected: 
/sys/bus/i2c/device/2-0048 - 
protocol - i2c
bus - 2
adderss - 0048

2. **Class view** - functionality/type
usually applications use this, this exposes the higher values such as values, thresholds etc, here the devices are classified according to the functionality
/sys/class/hwmon/hwmon0

Here I assume, the values under /sys/class/hwmon/hwmon* as well as /sys/bus/i2c/device/*-****



