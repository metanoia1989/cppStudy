#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from gi.repository import Notify, GdkPixbuf

Notify.init("App")
notification = Notify.Notification.new("Alert!")

# 使用 GdkPixbuf 创建图片类型
image = GdkPixbuf.Pixbuf.new_from_file("./community.png")
# notification.set_icon_from_pixbuf(image)
notification.set_image_from_pixbuf(image)

notification.show()