EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:ESP8266
LIBS:pca9685
LIBS:lighthing-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP-07v2 U?
U 1 1 56E48F3F
P 3400 2650
F 0 "U?" H 3400 2550 50  0000 C CNN
F 1 "ESP-07v2" H 3400 2750 50  0000 C CNN
F 2 "" H 3400 2650 50  0001 C CNN
F 3 "" H 3400 2650 50  0001 C CNN
	1    3400 2650
	1    0    0    -1  
$EndComp
$Comp
L Q_NJFET_DGS Q?
U 1 1 56E48FC0
P 9800 1650
F 0 "Q?" H 10100 1700 50  0000 R CNN
F 1 "Q_NJFET_DGS" H 10450 1600 50  0000 R CNN
F 2 "" H 10000 1750 50  0000 C CNN
F 3 "" H 9800 1650 50  0000 C CNN
	1    9800 1650
	1    0    0    -1  
$EndComp
$Comp
L PCA9685 U?
U 1 1 56E49269
P 6350 3600
F 0 "U?" H 6350 3500 50  0000 C CNN
F 1 "PCA9685" H 6100 1950 50  0000 C CNN
F 2 "MODULE" H 6650 1950 50  0001 C CNN
F 3 "DOCUMENTATION" H 6500 5250 50  0001 C CNN
	1    6350 3600
	1    0    0    -1  
$EndComp
Entry Wire Line
	7150 3500 7250 3600
Entry Wire Line
	7150 3300 7250 3400
Entry Wire Line
	7150 3100 7250 3200
Entry Wire Line
	7150 2900 7250 3000
Entry Wire Line
	7150 2700 7250 2800
Entry Wire Line
	7150 2500 7250 2600
Entry Wire Line
	7150 2300 7250 2400
Entry Wire Line
	7150 2100 7250 2200
Wire Wire Line
	7150 2100 7100 2100
Wire Wire Line
	7100 2500 7150 2500
Wire Wire Line
	7100 2300 7150 2300
Wire Wire Line
	7100 2700 7150 2700
Wire Wire Line
	7100 2900 7150 2900
Wire Wire Line
	7100 3100 7150 3100
Wire Wire Line
	7100 3300 7150 3300
Wire Wire Line
	7100 3500 7150 3500
Wire Bus Line
	7250 2200 7250 3650
Wire Bus Line
	7250 3650 7450 3650
Text Label 7150 2100 0    60   ~ 0
LED0
Text Label 7150 2300 0    60   ~ 0
LED1
Text Label 7150 2500 0    60   ~ 0
LED2
Text Label 7150 2700 0    60   ~ 0
LED3
$EndSCHEMATC
