## PID Control

The goals / steps of this project are the following:

* Design PID controller 
* Tune PID controller sucha that car completes lap around track
* No tire may leave the drivable portion of the track surface.
* The car may not pop up onto ledges or roll over any surfaces that would otherwise be considered unsafe



---
[//]: # (Image References)

[image1]: ./output_images/PID_image.JPG "PID Block Diagram"
[image2]: ./output_images/ModifiedPID.JPG "Modified PID Block Diagram"
[image3]: ./output_images/iPID.JPG "Effect of integral term"
[image4]: ./output_images/dPID.JPG "Effect of derivative term"



## [Rubric](https://review.udacity.com/#!/rubrics/1972/view) Points

---

## PID Controller
PID controller is a classical feedback control which determine corrective action to plant based on error between setpoint and measured variable. As name suggests, PID control has three terms proportional, integral and derivative.


### Proportional Control (P): 
Proptional control defines control input directly proprtional to error. Proportional control is linear relation with error term and this results into output oscilates around setpoint.


### Integral Control (I):
Integral control integrates error term over time and determine control output based on integrated error. Purspose of integral control is to imrove steady state bahaviour. and remove any steady state error/offset. It should be noted that we can no  have only integral conrol and it could be either PI controller or PID control.


### Derivative control (D):
Derivative control used derivative of error to determine control input. Purpose of derivative term to improve transient response. It can remove osscilation around setpoint due to proportional term and even improve rise time. Derivative term along with proportional term may lead to steady state offset that can be eliminated by integration term.


A combination of all three term in controller is termed as PID controller. Based on plant model and desired behavior, one can choose best combination from Proportional(P), Proportional-Integral(PI), Proportional-Derivative(PD) and Proportional-Integral-Derivative (PID).


## PID Control Implementation
Goal of Project to minimise crosstrack error in order to drive car on complex track. A PID control block should appear as following:
![alt text][image1]


However lateral distance is not only propotional to steer angle but speed as well. This mean same corrective action on steering can results into two different outcome on low speed and high speed. To counter this I have modified my error variable e(t) into e'(t) where e'(t) = cte/speed when speed >10mph when speed is <10mph e'(t) =cte/10. This can be represented as
![alt text][image2]

My new error term is linear with steeriing and it maked tuning much easier.


I also implemented a not so perfect PI controller for speed to maintain speed of 50mph throughout the lap.

## PID Tuning
I wanted to used Twiddle to tune my PID control but my inability to run simulator directly from command line forced me to opt for manual tuning. I took inspiration from Ziegler-Nichols method and twiddle to get PID parameter to make car complete the lap. I started increasing P value and when car is getting off the track then I add some derivative term so that derivative term can uses error delta and influence steering to be able to keep on track. when PD value is not able to  keep vehicle on track I added integral term to bring to centreline. I repeated multiple time until car is able to complete the lap. After that I started playing with p term to get maximum value for my proportion term and started using twiddle kind of method to get right PID parameter.

![alt text][image3]

![alt text][image4]



## Reflection
PID parameters are not tuned properly but with keeping effort invested in manual tuning and GPU time, car is able to run on track with these value. PID controler should be tunned with online tunning method to get best results. Another improvement could be create cascade control with speed as inner loop wwhich can discourage throttle demand with greater steer demand.
