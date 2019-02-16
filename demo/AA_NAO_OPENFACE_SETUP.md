Setup demo for NAO and CAMERA (openface)
---
One important variable is the number of version of the demo.

* v07 for the Sat 16 Feb 10:11:42 GMT 2019  (~/tmp/openday_v07)



# Setting Up

1. Create path to save data

```
mkdir -p ~/tmp/openday_v07
```


# NAO
The boot process is completed when NAO says “OGNAK GNOUK” and it takes around
2minutes 13 seconds, then you can establish the network connection with NAO
(selecting NAO in the in the network options)
and open a terminal to execute nao's movements with the python script.

## TERMINAL 1

```
cd ~/opendayuob-hridemo/nao_arm_movements/python_animation && python TenUpperArmMovements_changingspeed.py

```

The execution time for 
`sh TenUpperArmMovements_changingspeed.py`
is 34 seconds.



# OPENFACE [3]
Make sure that `sh openface_pNN.sh` is using the right path to save
video files, that is: `cd /home/map479/tmp/openday_v07 && mkdir -p openface && cd openface`
So, open file and edit it:

```
vim openface_pNN.sh
```
then change version of openday vNN
```
cd /home/map479/tmp/openday_v07 && mkdir -p openface && cd openface
```




## TERMINAL 3

```
cd ~/mxochicale/github/opendayuob-hridemo/demo && sleep 10 && sh openface_pNN.sh pNNgXXaNN
```
sleep 10 seconds to wait for the instructions with NAO 

Press `ctrl-q` in the video window to exit

then the script will compute the landmarks of the video
and replay the video with facelandmarks
Press `ctrl-q` to exit


# DATA PATHS

```
cd ~/tmp/openday_v07
```

#  REFERENCE

[1] [automatic_connection](https://github.com/mxochicale/ros/tree/master/bluetooth_dev_conf/automatic_connection)  
[2] Further information about package configuration [mx_razor_imu_9dof/catkin_ws](https://github.com/mxochicale/ros/tree/master/mx_razor_imu_9dof/catkin_ws)  
[3] https://github.com/mxochicale/openface  




