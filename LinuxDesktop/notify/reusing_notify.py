#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from gi.repository import Notify
import time

Notify.init("星火商店 - 程序名")
notification = Notify.Notification.new("Hi")
notification.show()


# 等待1s，然后更新提醒内容，重新发布提醒
time.sleep(1)

notification.set_app_name("星火商店 - 啦啦啦")
notification.update("叮咚！", "非常非常地有魅力")
notification.show()