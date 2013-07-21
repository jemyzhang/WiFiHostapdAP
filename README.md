WiFiHostapdAP
=============

WiFi Hostapd AP clone from http://wifi-hostapd-ap.googlecode.com/
WiFi分享器，可用于Ubuntu或其他Linux发行版。源程序来源：[click](http://wifi-hostapd-ap.googlecode.com)

## 依赖
> sudo apt-get install wireless-tools bridge-utils hostapd dnsmasq libqtgui4

## 配置
- 驱动型号: nl80211
- Country Code: US
- Protection: 最好选择WPA-PSK

## 问题与排除：
无法激活,或出现错误,或激活完成但是没有绿色的Active字样.

1. 没有编辑/etc/init.d/hostapd文件,请按前面的方法修改该文件

2. 设置选项的第二页没有设置正确,或驱动选择不正确,或网卡没有选对,或者是其他地方出错

3. 密码设置不正确.
尝试取消密码

4. 保证你的无线网卡是开启的：
> $ ifconfig wlan0 up#如果出现了rfkill的报错

> $ rfkill list                        #查看你的无线设备

> $ rfkill unblock 2                #将你对应的无线设备解锁如果你只有一个无线设备的话，可以直接下面这样

> $ rfkill unblock all                #将所有无线设备都解锁

5. sudohostapd -d 可以显示错误信息
在命令行下运行程序，也能看到错误信息 
> $ sudo ./WiFi_Hostapd_AP

> $ hostapd /etc/hostapd/hostapd.conf #可以排除配置信息是否有出错

6. 如果是说WEP的key配置文件中出错
可以将/etc/hostapd/hostapd.conf中wep\_key0="12345678" #加上双引号,具体hostapd.conf的格式，可以看这个样例。

7. 激活成功,但是移动设备无法上网:
1:ap的ip与客户分配的ip不在同一程序段内
2:选择了错误的访问英特网的适配器(第三页DNSMASQ设置)

