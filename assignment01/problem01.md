# Problem Statement
Using the telegraph example, and the challenges listed in the module as reference, and describe
another device that you would like to discuss. Describe how you think its embedded system
works, and what design challenges it presents?

# Answer - Apple AirPods
## Implementation
I think the AirPod's embedded system is comprised of atleast the following modules:
- *Power* 
  - the AirPod's must employ a power consumption system to limit the power consumption when functionalities are not in use (i.e. toggling noise cancellation)
  - the AirPod's must have a battery built-in to charge the pair of earbuds, as well as a way to charge the main battery when the device is plugged in
- *Bluetooth*
  - the AirPod's must have a Bluetooth controller to handle requests, input-ouput data, and errors from external devives
- *Signal Processing*
  - the AirPod's must have a system to process digital signals received from an external device
  - the AirPod's must have a system to process analog signals received from the external enviroment (i.e. for noise cancellation purposes)
  - the AirPod's must have a system to process digital signals to an analog output for audio playing  
- Haptic Feedback
  - The AirPod's must have a system to handle the haptic feedback response of the user to process a: pause, song skip, etc.
  
## Challenges
In tanget with the implementation details above, I believe the following design challenges of AirPod's are:
- *Power*
  - Minimum requirement for operation time of the AirPod's. The AirPod's must employ some way to limit power consumption or else the device will not last long, which will impact customer experience and sales
- *Bluetooth*
  - Response: The AirPod's should be able to handle any device that supports Bluetooth, as well as handling the requests and data without user input.
  - Throughput: The AirPod's should be able to handle the data stream and commands from a connect device. 
- *Cost*
  - The AirPod's hardware must meet an expected BOM cost compete/meet sales quote while maintaining product performance and functionality
  - Plays a part in Memory Space, Footprint, etc. 
- *Footprint*
  - The AirPod's must meet a certain footprint size for customer experience and mechanical fit. Therefore, the parts picked should support the achievement layout and functionality
- *Security*
  - The AirPod's must employ some level of security such that any stranger/external device can interrupt Bluetooth connection, or randomly connect to the AirPod's
- *Durability*
  - The AirPod's must be able to endure everyday use through various activities. 


