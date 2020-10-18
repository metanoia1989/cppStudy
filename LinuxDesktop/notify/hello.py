#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from gi.repository import Notify
import time

Notify.init("星火商店")
notify = Notify.Notification.new("欢迎访问呢星火商店")
notify.show()

time.sleep(1.5)
Notify.Notification.close(notify)