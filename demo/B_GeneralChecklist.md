General Checklist
---


# Terminals
Open four terminals

## T1. for imus with three tabs 

* Tab1. Binding ports for IMUS
```
cd ~/mxochicale/github/ros/bluetooth_dev_conf/automatic_connection && ./bind_four_automatic_connection_ubuntu1604.sh && sleep 15
```

* Tab2. roslauch

```
roslaunch razor_imu_9dof razor-pub-four-imus.launch
```


* Tab3. Release ports for IMUS

```
cd ~/mxochicale/github/ros/bluetooth_dev_conf/automatic_connection && ./release_four_automatic_connection_ubuntu1604.sh
```

## T2. for openface

```
cd ~/mxochicale/github/opendayuob-hridemo/demo && sleep 10 && ./openface_pNN.sh pNNgXXaNN
```



## T3. for nao


```
cd ~/mxochicale/github/opendayuob-hridemo/nao_arm_movements/python_animation && sleep 5 && ./TenUpperArmMovements_changingspeed.py
```


## T4. for extra notes and datapath

```
cd /home/map479/tmp/openday_v05
```





# General Check List

1. Turn on IMUs
2. Bind them
	(prepare other terminals with names and files to be lauch)

3. MAIN LAUNCH
	A. NAO
	B. Openface
	C. roslauch

4. DEMO AND DATA COLLECTION IN EXECUTION
5. stop IMU streaming with CTRL-C
6. release sensors
7. Turn off sensors
8. stop openface CTRL-Q
9. stop openface video loop with CTRL-Q



