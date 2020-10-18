#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from gi.repository import Notify
import time


Notify.init("星火商店 - 程序名")
notification = Notify.Notification.new("Hi")


for i in [0, 1, 2]:
    # 0 low, 1 normal, 2 critical
    notification.set_urgency(i) 
    notification.show()
    time.sleep(1)
