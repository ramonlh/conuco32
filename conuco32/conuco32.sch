EESchema Schematic File Version 4
LIBS:conuco32-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Conuco 32 "
Date "2019-04-04"
Rev "1.0"
Comp "Conuco Labs"
Comment1 "R.L.H."
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Converter_ACDC:HLK-PM01 PS1
U 1 1 5CA4E297
P 2100 1350
F 0 "PS1" H 2100 1675 50  0000 C CNN
F 1 "HLK-PM01" H 2100 1584 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 2100 1050 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=54" H 2500 1000 50  0001 C CNN
	1    2100 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Network04 RN2
U 1 1 5CA52ADB
P 4500 2350
F 0 "RN2" H 4688 2396 50  0000 L CNN
F 1 "4x10K" H 4688 2305 50  0000 L CNN
F 2 "Resistor_THT:R_Array_SIP5" V 4775 2350 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 4500 2350 50  0001 C CNN
	1    4500 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Pack04 RN1
U 1 1 5CA556D2
P 2700 3400
F 0 "RN1" V 2283 3400 50  0000 C CNN
F 1 "4x330" V 2374 3400 50  0000 C CNN
F 2 "Package_SIP:SIP-8_19x3mm_P2.54mm" V 2975 3400 50  0001 C CNN
F 3 "~" H 2700 3400 50  0001 C CNN
	1    2700 3400
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x05 J2
U 1 1 5CA56EC2
P 1900 3400
F 0 "J2" H 1818 3725 50  0000 C BNN
F 1 "Input" H 1818 3726 50  0000 C TNN
F 2 "TerminalBlock:TerminalBlock_bornier-5_P5.08mm" H 1900 3400 50  0001 C CNN
F 3 "~" H 1900 3400 50  0001 C CNN
	1    1900 3400
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J4
U 1 1 5CA579DE
P 1900 5450
F 0 "J4" H 1818 5675 50  0000 C BNN
F 1 "ADC" H 1818 5676 50  0000 C TNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 1900 5450 50  0001 C CNN
F 3 "~" H 1900 5450 50  0001 C CNN
	1    1900 5450
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x04 J3
U 1 1 5CA58514
P 1900 4700
F 0 "J3" H 1818 4925 50  0000 C BNN
F 1 "DAC/1Wire" H 1818 4926 50  0000 C TNN
F 2 "TerminalBlock:TerminalBlock_bornier-4_P5.08mm" H 1900 4700 50  0001 C CNN
F 3 "~" H 1900 4700 50  0001 C CNN
	1    1900 4700
	-1   0    0    -1  
$EndComp
$Comp
L Device:Varistor RV1
U 1 1 5CA5BE6B
P 1350 1400
F 0 "RV1" H 1453 1446 50  0000 L CNN
F 1 "Varistor" H 1453 1355 50  0000 L CNN
F 2 "Varistor:RV_Disc_D9mm_W3.3mm_P5mm" V 1280 1400 50  0001 C CNN
F 3 "~" H 1350 1400 50  0001 C CNN
	1    1350 1400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5CA5C60C
P 900 1250
F 0 "J1" H 818 1375 50  0000 C BNN
F 1 "230v" H 818 1376 50  0000 C TNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 900 1250 50  0001 C CNN
F 3 "~" H 900 1250 50  0001 C CNN
	1    900  1250
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5CA5D4F7
P 2750 1400
F 0 "C1" H 2865 1446 50  0000 L CNN
F 1 "100n" H 2865 1355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 2788 1250 50  0001 C CNN
F 3 "~" H 2750 1400 50  0001 C CNN
	1    2750 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5CA5DD7F
P 3100 1400
F 0 "C2" H 3218 1446 50  0000 L CNN
F 1 "100mF" H 3218 1355 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 3138 1250 50  0001 C CNN
F 3 "~" H 3100 1400 50  0001 C CNN
	1    3100 1400
	1    0    0    -1  
$EndComp
$Comp
L Transistor_Array:ULN2803A U2
U 1 1 5CA5EA78
P 7950 3600
F 0 "U2" H 7950 4167 50  0000 C CNN
F 1 "ULN2803A" H 7950 4076 50  0000 C CNN
F 2 "Package_SO:SOP-18_7.0x12.5mm_P1.27mm" H 8000 2950 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/uln2803a.pdf" H 8050 3400 50  0001 C CNN
	1    7950 3600
	1    0    0    -1  
$EndComp
$Comp
L Relay:FINDER-34.51 K2
U 1 1 5CA5FFB1
P 9450 2750
F 0 "K2" V 8883 2750 50  0000 C CNN
F 1 "FINDER-34.51" V 8974 2750 50  0000 C CNN
F 2 "Relay_THT:Relay_SPDT_Finder_34.51_Vertical" H 10590 2710 50  0001 C CNN
F 3 "https://gfinder.findernet.com/public/attachments/34/EN/S34USAEN.pdf" H 9450 2750 50  0001 C CNN
	1    9450 2750
	0    1    1    0   
$EndComp
$Comp
L Relay:FINDER-34.51 K1
U 1 1 5CA610C2
P 9450 1750
F 0 "K1" V 8883 1750 50  0000 C CNN
F 1 "FINDER-34.51" V 8974 1750 50  0000 C CNN
F 2 "Relay_THT:Relay_SPDT_Finder_34.51_Vertical" H 10590 1710 50  0001 C CNN
F 3 "https://gfinder.findernet.com/public/attachments/34/EN/S34USAEN.pdf" H 9450 1750 50  0001 C CNN
	1    9450 1750
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J5
U 1 1 5CA626E0
P 10600 1950
F 0 "J5" H 10680 1946 50  0000 L BNN
F 1 "R1" H 10680 1901 50  0000 L BNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 10600 1950 50  0001 C CNN
F 3 "~" H 10600 1950 50  0001 C CNN
	1    10600 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J6
U 1 1 5CA63517
P 10600 2950
F 0 "J6" H 10680 2946 50  0000 C BNN
F 1 "R2" H 10680 2901 50  0000 C BNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 10600 2950 50  0001 C CNN
F 3 "~" H 10600 2950 50  0001 C CNN
	1    10600 2950
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5CA64F40
P 7950 4500
F 0 "#PWR07" H 7950 4250 50  0001 C CNN
F 1 "GND" H 7955 4327 50  0000 C CNN
F 2 "" H 7950 4500 50  0001 C CNN
F 3 "" H 7950 4500 50  0001 C CNN
	1    7950 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4300 7950 4400
$Comp
L Connector:Conn_01x08_Female J7
U 1 1 5CA7B248
P 8950 3800
F 0 "J7" H 8978 3776 50  0000 L CNN
F 1 "Relays 3-8" H 8978 3685 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 8950 3800 50  0001 C CNN
F 3 "~" H 8950 3800 50  0001 C CNN
	1    8950 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 3600 8750 3600
Wire Wire Line
	8350 3300 8400 3300
Wire Wire Line
	8650 3300 8650 3500
Wire Wire Line
	8650 3500 8750 3500
Wire Wire Line
	8750 3700 8350 3700
Wire Wire Line
	8350 3800 8750 3800
Wire Wire Line
	8350 3900 8750 3900
Wire Wire Line
	8350 4000 8750 4000
Wire Wire Line
	8350 4100 8750 4100
Wire Wire Line
	8750 4200 8650 4200
Wire Wire Line
	8650 4200 8650 4400
Wire Wire Line
	8650 4400 7950 4400
Wire Wire Line
	8350 3500 8550 3500
Wire Wire Line
	8550 3500 8550 2550
Wire Wire Line
	8350 3400 8500 3400
$Comp
L power:+5V #PWR08
U 1 1 5CA8928E
P 8200 1000
F 0 "#PWR08" H 8200 850 50  0001 C CNN
F 1 "+5V" H 8215 1173 50  0000 C CNN
F 2 "" H 8200 1000 50  0001 C CNN
F 3 "" H 8200 1000 50  0001 C CNN
	1    8200 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1000 8200 1050
Connection ~ 8400 3300
Wire Wire Line
	8400 3300 8650 3300
Wire Wire Line
	10050 1050 9000 1050
Connection ~ 8200 1050
Wire Wire Line
	8400 1050 8400 3300
Wire Wire Line
	9750 2550 10050 2550
Wire Wire Line
	9750 1850 10400 1850
Wire Wire Line
	9750 2050 10400 2050
Wire Wire Line
	9150 1950 9000 1950
Wire Wire Line
	9000 1950 9000 2200
Wire Wire Line
	9000 2200 10250 2200
Wire Wire Line
	10250 2200 10250 1950
Wire Wire Line
	10250 1950 10400 1950
Wire Wire Line
	9750 2850 10400 2850
Wire Wire Line
	9750 3050 10400 3050
Wire Wire Line
	9150 2950 9000 2950
Wire Wire Line
	9000 2950 9000 3200
Wire Wire Line
	9000 3200 10250 3200
Wire Wire Line
	10250 3200 10250 2950
Wire Wire Line
	10250 2950 10400 2950
$Comp
L power:GND #PWR06
U 1 1 5CAAFC22
P 4200 4750
F 0 "#PWR06" H 4200 4500 50  0001 C CNN
F 1 "GND" H 4205 4577 50  0000 C CNN
F 2 "" H 4200 4750 50  0001 C CNN
F 3 "" H 4200 4750 50  0001 C CNN
	1    4200 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3400 4200 3400
Wire Wire Line
	4200 3400 4200 3750
Wire Wire Line
	4050 3750 4200 3750
Connection ~ 4200 3750
Wire Wire Line
	4200 3750 4200 4150
Connection ~ 4200 4150
Wire Wire Line
	4200 4150 4200 4550
Wire Wire Line
	4050 4150 4200 4150
Wire Wire Line
	4050 4550 4200 4550
Connection ~ 4200 4550
Wire Wire Line
	4200 4550 4200 4700
Wire Wire Line
	2900 3200 3450 3200
Wire Wire Line
	2900 3300 3200 3300
Wire Wire Line
	3200 3300 3200 3550
Wire Wire Line
	3200 3550 3450 3550
Wire Wire Line
	2900 3400 3150 3400
Wire Wire Line
	3150 3400 3150 3950
Wire Wire Line
	3150 3950 3450 3950
Wire Wire Line
	2900 3500 3100 3500
Wire Wire Line
	3100 3500 3100 4350
Wire Wire Line
	3100 4350 3450 4350
Wire Wire Line
	3450 3400 3300 3400
Wire Wire Line
	3300 3400 3300 3750
Wire Wire Line
	3300 4700 4200 4700
Connection ~ 4200 4700
Wire Wire Line
	4200 4700 4200 4750
Wire Wire Line
	3450 3750 3300 3750
Connection ~ 3300 3750
Wire Wire Line
	3300 3750 3300 4150
Wire Wire Line
	3450 4150 3300 4150
Connection ~ 3300 4150
Wire Wire Line
	3300 4150 3300 4550
Wire Wire Line
	3450 4550 3300 4550
Connection ~ 3300 4550
Wire Wire Line
	3300 4550 3300 4700
$Comp
L power:GND #PWR01
U 1 1 5CAF488C
P 2200 3750
F 0 "#PWR01" H 2200 3500 50  0001 C CNN
F 1 "GND" H 2205 3577 50  0000 C CNN
F 2 "" H 2200 3750 50  0001 C CNN
F 3 "" H 2200 3750 50  0001 C CNN
	1    2200 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 3600 2200 3600
Wire Wire Line
	2200 3600 2200 3750
$Comp
L power:+5V #PWR02
U 1 1 5CB25A5A
P 2200 4200
F 0 "#PWR02" H 2200 4050 50  0001 C CNN
F 1 "+5V" H 2215 4373 50  0000 C CNN
F 2 "" H 2200 4200 50  0001 C CNN
F 3 "" H 2200 4200 50  0001 C CNN
	1    2200 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 4700 2200 4700
$Comp
L power:GND #PWR03
U 1 1 5CB3A7FB
P 2200 5700
F 0 "#PWR03" H 2200 5450 50  0001 C CNN
F 1 "GND" H 2205 5527 50  0000 C CNN
F 2 "" H 2200 5700 50  0001 C CNN
F 3 "" H 2200 5700 50  0001 C CNN
	1    2200 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 5550 2200 5550
Wire Wire Line
	2200 5550 2200 5700
Wire Wire Line
	1350 1250 1700 1250
Connection ~ 1350 1250
Wire Wire Line
	2500 1250 2750 1250
Wire Wire Line
	2750 1250 3100 1250
Connection ~ 2750 1250
$Comp
L power:+5V #PWR04
U 1 1 5CB7420C
P 3500 1150
F 0 "#PWR04" H 3500 1000 50  0001 C CNN
F 1 "+5V" H 3515 1323 50  0000 C CNN
F 2 "" H 3500 1150 50  0001 C CNN
F 3 "" H 3500 1150 50  0001 C CNN
	1    3500 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5CB7516F
P 3500 1650
F 0 "#PWR05" H 3500 1400 50  0001 C CNN
F 1 "GND" H 3505 1477 50  0000 C CNN
F 2 "" H 3500 1650 50  0001 C CNN
F 3 "" H 3500 1650 50  0001 C CNN
	1    3500 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1250 3500 1250
Wire Wire Line
	3500 1250 3500 1150
Connection ~ 3100 1250
Wire Wire Line
	2500 1450 2600 1450
Wire Wire Line
	2600 1450 2600 1550
Wire Wire Line
	2600 1550 2750 1550
Wire Wire Line
	2750 1550 3100 1550
Connection ~ 2750 1550
Wire Wire Line
	3100 1550 3500 1550
Wire Wire Line
	3500 1550 3500 1650
Connection ~ 3100 1550
Wire Wire Line
	1600 1450 1600 1550
Wire Wire Line
	1600 1550 1350 1550
Wire Wire Line
	1600 1450 1700 1450
Wire Wire Line
	1100 1250 1350 1250
Wire Wire Line
	1200 1350 1200 1550
Wire Wire Line
	1200 1550 1350 1550
Wire Wire Line
	1100 1350 1200 1350
Connection ~ 1350 1550
$Comp
L Connector:Conn_01x02_Male J8
U 1 1 5CBC469B
P 4900 1250
F 0 "J8" V 5054 1062 50  0000 R CNN
F 1 "RST" V 4963 1062 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4900 1250 50  0001 C CNN
F 3 "~" H 4900 1250 50  0001 C CNN
	1    4900 1250
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5CBDD78B
P 5200 1950
F 0 "#PWR0101" H 5200 1700 50  0001 C CNN
F 1 "GND" H 5205 1777 50  0000 C CNN
F 2 "" H 5200 1950 50  0001 C CNN
F 3 "" H 5200 1950 50  0001 C CNN
	1    5200 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5CC2E68B
P 5900 4950
F 0 "#PWR0103" H 5900 4800 50  0001 C CNN
F 1 "+5V" H 5915 5123 50  0000 C CNN
F 2 "" H 5900 4950 50  0001 C CNN
F 3 "" H 5900 4950 50  0001 C CNN
	1    5900 4950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J10
U 1 1 5CC39613
P 6300 5450
F 0 "J10" V 6146 5598 50  0000 L CNN
F 1 "TX433" V 6237 5598 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 6300 5450 50  0001 C CNN
F 3 "~" H 6300 5450 50  0001 C CNN
	1    6300 5450
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 5550 5900 5650
$Comp
L power:GND #PWR0102
U 1 1 5CC25767
P 5900 5650
F 0 "#PWR0102" H 5900 5400 50  0001 C CNN
F 1 "GND" H 5905 5477 50  0000 C CNN
F 2 "" H 5900 5650 50  0001 C CNN
F 3 "" H 5900 5650 50  0001 C CNN
	1    5900 5650
	1    0    0    -1  
$EndComp
Connection ~ 5900 5550
Wire Wire Line
	5900 5150 5900 4950
Wire Wire Line
	6300 5250 6300 5150
Connection ~ 5900 5150
$Comp
L Connector:Conn_01x03_Female J11
U 1 1 5CD02307
P 7050 5450
F 0 "J11" V 6896 5598 50  0000 L CNN
F 1 "Serial" V 6987 5598 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 7050 5450 50  0001 C CNN
F 3 "~" H 7050 5450 50  0001 C CNN
	1    7050 5450
	0    1    1    0   
$EndComp
Wire Wire Line
	7450 5150 7450 5550
$Comp
L Connector:Conn_01x04_Female J12
U 1 1 5CD363D3
P 8750 5450
F 0 "J12" V 8596 5598 50  0000 L CNN
F 1 "I2C" V 8687 5598 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 8750 5450 50  0001 C CNN
F 3 "~" H 8750 5450 50  0001 C CNN
	1    8750 5450
	0    1    1    0   
$EndComp
Wire Wire Line
	7150 5150 7200 5150
Wire Wire Line
	4300 1050 8200 1050
Wire Wire Line
	4300 1050 4300 2150
$Comp
L Connector:Conn_01x02_Male J15
U 1 1 5CEA333E
P 8350 4900
F 0 "J15" H 8458 5081 50  0000 C CNN
F 1 "SDA" H 8458 4990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8350 4900 50  0001 C CNN
F 3 "~" H 8350 4900 50  0001 C CNN
	1    8350 4900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J16
U 1 1 5CEA59B1
P 8850 5000
F 0 "J16" H 8822 4882 50  0000 R CNN
F 1 "SCL" H 8822 4973 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8850 5000 50  0001 C CNN
F 3 "~" H 8850 5000 50  0001 C CNN
	1    8850 5000
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 4500 7950 4400
Connection ~ 7950 4400
Wire Wire Line
	8550 5250 8550 5000
Wire Wire Line
	8650 5250 8650 5000
$Comp
L power:GND #PWR0104
U 1 1 5CFA05A0
P 9200 5600
F 0 "#PWR0104" H 9200 5350 50  0001 C CNN
F 1 "GND" H 9205 5427 50  0000 C CNN
F 2 "" H 9200 5600 50  0001 C CNN
F 3 "" H 9200 5600 50  0001 C CNN
	1    9200 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 5250 8850 5150
Wire Wire Line
	8850 5150 9200 5150
$Comp
L power:+5V #PWR0105
U 1 1 5CFACEE3
P 9200 4700
F 0 "#PWR0105" H 9200 4550 50  0001 C CNN
F 1 "+5V" H 9215 4873 50  0000 C CNN
F 2 "" H 9200 4700 50  0001 C CNN
F 3 "" H 9200 4700 50  0001 C CNN
	1    9200 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 5250 8750 5100
Wire Wire Line
	8750 5100 9200 5100
Wire Wire Line
	9200 5100 9200 4700
$Comp
L Connector:Conn_01x04_Female J13
U 1 1 5CA79F50
P 4700 5450
F 0 "J13" V 4546 5598 50  0000 L CNN
F 1 "SPI" V 4637 5598 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 4700 5450 50  0001 C CNN
F 3 "~" H 4700 5450 50  0001 C CNN
	1    4700 5450
	0    1    1    0   
$EndComp
Wire Wire Line
	9200 5150 9200 5600
Wire Wire Line
	6300 5150 5900 5150
Wire Wire Line
	5500 5050 5500 5250
Wire Wire Line
	5400 5050 5500 5050
Wire Wire Line
	5400 5050 5400 5250
Wire Wire Line
	5600 5150 5900 5150
Wire Wire Line
	5600 5250 5600 5150
Wire Wire Line
	5300 5150 5100 5150
Wire Wire Line
	5300 5250 5300 5150
$Comp
L Connector:Conn_01x04_Female J9
U 1 1 5CBF26B0
P 5500 5450
F 0 "J9" V 5346 5598 50  0000 L CNN
F 1 "RX433" V 5437 5598 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 5500 5450 50  0001 C CNN
F 3 "~" H 5500 5450 50  0001 C CNN
	1    5500 5450
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 5550 5900 5550
Wire Wire Line
	5100 5150 5100 5550
$Comp
L Connector:Conn_01x04_Female J14
U 1 1 5CBA01DE
P 5950 1250
F 0 "J14" V 5796 1398 50  0000 L CNN
F 1 "Touch" V 5887 1398 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 5950 1250 50  0001 C CNN
F 3 "~" H 5950 1250 50  0001 C CNN
	1    5950 1250
	0    1    -1   0   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5CBF7A8F
P 4550 1800
F 0 "SW1" V 4596 1752 50  0000 R CNN
F 1 "RST" V 4505 1752 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H8mm" H 4550 2000 50  0001 C CNN
F 3 "~" H 4550 2000 50  0001 C CNN
	1    4550 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4550 1600 4550 1550
Wire Wire Line
	4550 2000 4550 2050
Wire Wire Line
	4550 2050 4700 2050
Wire Wire Line
	5000 1450 5000 1550
Wire Wire Line
	4550 1550 5000 1550
Wire Wire Line
	4900 1450 4900 2050
Wire Wire Line
	10050 1050 10050 2550
Wire Wire Line
	9900 1150 9900 1550
Wire Wire Line
	9900 1550 9750 1550
Wire Wire Line
	8500 1150 8500 3400
Wire Wire Line
	9150 1550 9000 1550
Wire Wire Line
	9000 1550 9000 1050
Connection ~ 9000 1050
Wire Wire Line
	9000 1050 8400 1050
Wire Wire Line
	5000 1550 5000 2900
Connection ~ 5000 1550
Wire Wire Line
	5200 1550 5000 1550
Wire Wire Line
	5200 1550 5200 1950
$Comp
L ESP32-DEVKITC-32D:ESP32-DEVKITC-32D-Conuco_Mini U4
U 1 1 5CAB14E3
P 5800 3800
F 0 "U4" H 5800 4965 50  0000 C CNN
F 1 "ESP32-DEVKITC-32D-Conuco_Mini" H 5800 4874 50  0000 C CNN
F 2 "conucos:MODULE_ESP32-DEVKIT-32D-ConucoMini" H 4950 2600 50  0001 L BNN
F 3 "" H 5450 3400 50  0001 L BNN
F 4 "Espressif Systems" H 5450 2500 50  0001 L BNN "Field4"
F 5 "Conuco Labs" H 5450 2400 50  0001 L BNN "Field5"
F 6 "HW665" H 5950 2400 50  0001 L BNN "Field6"
	1    5800 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3200 4300 3200
Wire Wire Line
	5000 3900 4600 3900
Wire Wire Line
	4350 3900 4350 4350
Wire Wire Line
	4350 4350 4050 4350
Wire Wire Line
	5000 3500 4500 3500
Wire Wire Line
	4300 3500 4300 3950
Wire Wire Line
	4300 3950 4050 3950
Wire Wire Line
	5000 3300 4400 3300
Wire Wire Line
	4250 3300 4250 3550
Wire Wire Line
	4250 3550 4050 3550
Wire Wire Line
	6500 3200 6950 3200
Wire Wire Line
	6950 3200 6950 5250
Wire Wire Line
	5000 4100 4500 4100
Wire Wire Line
	4500 4100 4500 5250
Wire Wire Line
	5100 4600 4600 4600
Wire Wire Line
	4600 4600 4600 5250
Wire Wire Line
	6500 4600 6650 4600
Wire Wire Line
	6650 4600 6650 4950
Wire Wire Line
	4700 4950 4700 5250
Wire Wire Line
	6600 3700 6750 3700
Wire Wire Line
	6750 3700 6750 5000
Wire Wire Line
	6750 5000 4800 5000
Wire Wire Line
	4800 5000 4800 5250
Wire Wire Line
	4700 4950 6650 4950
Wire Wire Line
	6500 3400 7100 3400
Wire Wire Line
	8650 4750 8650 4900
Wire Wire Line
	6500 3600 7050 3600
Wire Wire Line
	8550 4800 8550 4900
Wire Wire Line
	4200 5450 2100 5450
Wire Wire Line
	4250 5350 2100 5350
$Comp
L power:GND #PWR0106
U 1 1 5CD198BD
P 2200 5050
F 0 "#PWR0106" H 2200 4800 50  0001 C CNN
F 1 "GND" H 2205 4877 50  0000 C CNN
F 2 "" H 2200 5050 50  0001 C CNN
F 3 "" H 2200 5050 50  0001 C CNN
	1    2200 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 4900 2200 4900
Wire Wire Line
	2200 4900 2200 5050
Wire Wire Line
	6600 3900 6850 3900
Wire Wire Line
	6600 3100 6700 3100
Wire Wire Line
	4250 5950 6850 5950
Wire Wire Line
	4200 6000 6900 6000
Wire Wire Line
	4250 5350 4250 5950
Wire Wire Line
	4200 5450 4200 6000
Wire Wire Line
	6850 3900 6850 5950
Wire Wire Line
	6900 3100 6900 6000
Wire Wire Line
	6600 3300 6800 3300
Wire Wire Line
	6800 3300 6800 5900
Wire Wire Line
	6800 5900 4300 5900
Wire Wire Line
	4300 5900 4300 5300
Wire Wire Line
	4300 5300 2600 5300
Wire Wire Line
	2600 5300 2600 4800
Wire Wire Line
	2600 4800 2400 4800
Wire Wire Line
	5100 3400 4450 3400
Wire Wire Line
	4450 3400 4450 5250
Wire Wire Line
	4450 5250 2650 5250
Wire Wire Line
	2650 5250 2650 4600
Wire Wire Line
	2650 4600 2100 4600
Wire Wire Line
	4300 2550 4300 3200
Connection ~ 4300 3200
Wire Wire Line
	4300 3200 5100 3200
Wire Wire Line
	4400 2550 4400 3300
Connection ~ 4400 3300
Wire Wire Line
	4400 3300 4250 3300
Wire Wire Line
	4500 2550 4500 3500
Connection ~ 4500 3500
Wire Wire Line
	4500 3500 4300 3500
Wire Wire Line
	4600 2550 4600 3900
Connection ~ 4600 3900
Wire Wire Line
	4600 3900 4350 3900
Wire Wire Line
	7050 5250 7050 5150
Wire Wire Line
	7050 5150 7000 5150
Wire Wire Line
	6500 3000 7000 3000
Wire Wire Line
	7000 3000 7000 5150
Wire Wire Line
	7150 5150 7150 5250
Wire Wire Line
	7050 4800 8550 4800
Wire Wire Line
	7100 4750 8650 4750
Connection ~ 8400 1050
Wire Wire Line
	8400 1050 8200 1050
Wire Wire Line
	8500 1150 9900 1150
Wire Wire Line
	8550 2550 9150 2550
Wire Wire Line
	7050 3600 7050 4000
Wire Wire Line
	7100 3400 7100 4100
Wire Wire Line
	7050 4000 7550 4000
Connection ~ 7050 4000
Wire Wire Line
	7050 4000 7050 4800
Wire Wire Line
	7100 4100 7550 4100
Connection ~ 7100 4100
Wire Wire Line
	7100 4100 7100 4750
Wire Wire Line
	6500 4000 6700 4000
Wire Wire Line
	6700 4000 6700 3850
Wire Wire Line
	6700 3850 7400 3850
Wire Wire Line
	7400 3850 7400 3900
Wire Wire Line
	7400 3900 7550 3900
Wire Wire Line
	6500 3800 7550 3800
Wire Wire Line
	5100 3600 4950 3600
Wire Wire Line
	4950 3600 4950 2600
Wire Wire Line
	4950 2600 7250 2600
Wire Wire Line
	7250 2600 7250 3700
Wire Wire Line
	7250 3700 7550 3700
Wire Wire Line
	5100 3800 4900 3800
Wire Wire Line
	4900 3800 4900 2550
Wire Wire Line
	4900 2550 7300 2550
Wire Wire Line
	7300 2550 7300 3600
Wire Wire Line
	7300 3600 7550 3600
Wire Wire Line
	5100 4000 4850 4000
Wire Wire Line
	4850 4000 4850 2500
Wire Wire Line
	4850 2500 7350 2500
Wire Wire Line
	7350 2500 7350 3500
Wire Wire Line
	7350 3500 7550 3500
Wire Wire Line
	5100 4200 4800 4200
Wire Wire Line
	4800 4200 4800 2450
Wire Wire Line
	4800 2450 7400 2450
Wire Wire Line
	7400 2450 7400 3400
Wire Wire Line
	7400 3400 7550 3400
Wire Wire Line
	6600 3500 6750 3500
Wire Wire Line
	7150 3500 7150 5050
Wire Wire Line
	7150 5050 5500 5050
Connection ~ 5500 5050
Wire Wire Line
	5900 5550 7450 5550
Wire Wire Line
	6200 5250 6200 5200
Wire Wire Line
	6200 5200 5900 5200
Wire Wire Line
	5900 5200 5900 5550
Wire Wire Line
	6600 4300 6700 4300
Wire Wire Line
	6700 4300 6700 5150
Wire Wire Line
	6700 5150 6400 5150
Wire Wire Line
	6400 5150 6400 5250
Wire Wire Line
	5000 3700 4750 3700
Wire Wire Line
	4750 3700 4750 2400
Wire Wire Line
	4750 2400 5750 2400
Wire Wire Line
	5750 2400 5750 1450
Wire Wire Line
	6850 3900 6850 1600
Wire Wire Line
	6850 1600 6050 1600
Wire Wire Line
	6050 1600 6050 1450
Connection ~ 6850 3900
Wire Wire Line
	6700 3100 6700 1700
Wire Wire Line
	6700 1700 5850 1700
Wire Wire Line
	5850 1700 5850 1450
Connection ~ 6700 3100
Wire Wire Line
	6700 3100 6900 3100
Wire Wire Line
	6750 3500 6750 1650
Wire Wire Line
	6750 1650 5950 1650
Wire Wire Line
	5950 1650 5950 1450
Connection ~ 6750 3500
Wire Wire Line
	6750 3500 7150 3500
NoConn ~ 5000 4500
NoConn ~ 5000 4700
NoConn ~ 5100 4800
NoConn ~ 6600 4700
NoConn ~ 6500 4800
NoConn ~ 6600 4500
$Comp
L power:+5V #PWR0107
U 1 1 5D0B25DB
P 7350 4300
F 0 "#PWR0107" H 7350 4150 50  0001 C CNN
F 1 "+5V" H 7365 4473 50  0000 C CNN
F 2 "" H 7350 4300 50  0001 C CNN
F 3 "" H 7350 4300 50  0001 C CNN
	1    7350 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4400 7350 4400
Wire Wire Line
	7350 4400 7350 4300
Wire Wire Line
	6600 2900 7200 2900
Wire Wire Line
	7200 2900 7200 4200
Connection ~ 7200 5150
Wire Wire Line
	7200 5150 7450 5150
Wire Wire Line
	6500 4200 7200 4200
Connection ~ 7200 4200
Wire Wire Line
	7200 4200 7200 5150
Wire Wire Line
	5100 3000 4700 3000
Wire Wire Line
	4700 3000 4700 2050
Connection ~ 4700 2050
Wire Wire Line
	4700 2050 4900 2050
$Comp
L Isolator:LTV-847S U1
U 1 1 5D16FB94
P 3750 3300
F 0 "U1" H 3750 3625 50  0000 C CNN
F 1 "LTV-847S" H 3750 3534 50  0000 C CNN
F 2 "Package_DIP:SMDIP-16_W9.53mm" H 3750 3000 50  0001 C CNN
F 3 "http://www.us.liteon.com/downloads/LTV-817-827-847.PDF" H 3150 3750 50  0001 C CNN
	1    3750 3300
	1    0    0    -1  
$EndComp
$Comp
L Isolator:LTV-847S U1
U 2 1 5D1EC16A
P 3750 3650
F 0 "U1" H 3750 3975 50  0000 C CNN
F 1 "LTV-847S" H 3750 3884 50  0000 C CNN
F 2 "Package_DIP:SMDIP-16_W9.53mm" H 3750 3350 50  0001 C CNN
F 3 "http://www.us.liteon.com/downloads/LTV-817-827-847.PDF" H 3150 4100 50  0001 C CNN
	2    3750 3650
	1    0    0    -1  
$EndComp
$Comp
L Isolator:LTV-847S U1
U 3 1 5D1EDA0B
P 3750 4050
F 0 "U1" H 3750 4375 50  0000 C CNN
F 1 "LTV-847S" H 3750 4284 50  0000 C CNN
F 2 "Package_DIP:SMDIP-16_W9.53mm" H 3750 3750 50  0001 C CNN
F 3 "http://www.us.liteon.com/downloads/LTV-817-827-847.PDF" H 3150 4500 50  0001 C CNN
	3    3750 4050
	1    0    0    -1  
$EndComp
$Comp
L Isolator:LTV-847S U1
U 4 1 5D204948
P 3750 4450
F 0 "U1" H 3750 4775 50  0000 C CNN
F 1 "LTV-847S" H 3750 4684 50  0000 C CNN
F 2 "Package_DIP:SMDIP-16_W9.53mm" H 3750 4150 50  0001 C CNN
F 3 "http://www.us.liteon.com/downloads/LTV-817-827-847.PDF" H 3150 4900 50  0001 C CNN
	4    3750 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5CAF3E81
P 2400 4450
F 0 "R1" H 2459 4496 50  0000 L CNN
F 1 "10k" H 2459 4405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 2400 4450 50  0001 C CNN
F 3 "~" H 2400 4450 50  0001 C CNN
	1    2400 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 5CAF455A
P 2650 4450
F 0 "R2" H 2709 4496 50  0000 L CNN
F 1 "10k" H 2709 4405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 2650 4450 50  0001 C CNN
F 3 "~" H 2650 4450 50  0001 C CNN
	1    2650 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4550 2650 4600
Connection ~ 2650 4600
Wire Wire Line
	2400 4550 2400 4800
Connection ~ 2400 4800
Wire Wire Line
	2400 4800 2100 4800
Wire Wire Line
	2100 3200 2500 3200
Wire Wire Line
	2100 3300 2500 3300
Wire Wire Line
	2100 3400 2500 3400
Wire Wire Line
	2100 3500 2500 3500
Wire Wire Line
	2200 4200 2200 4250
Wire Wire Line
	2400 4350 2400 4250
Wire Wire Line
	2400 4250 2200 4250
Connection ~ 2200 4250
Wire Wire Line
	2200 4250 2200 4700
Wire Wire Line
	2650 4350 2650 4250
Wire Wire Line
	2650 4250 2400 4250
Connection ~ 2400 4250
$EndSCHEMATC
