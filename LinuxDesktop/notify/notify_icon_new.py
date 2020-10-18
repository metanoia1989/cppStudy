#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from gi.repository import Notify

Notify.init('App')

Notify.Notification.new(
    "Ding!",
    "Time is up",
    "/home/metanoia1989/WorkSpace/cppStudy/LinuxDesktop/notify/community.png"
).show()

Notify.Notification.new(
    "Ding!",
    "Time is up",
    "dialog-error" # dialog-information dialog-warn, dialog-error
).show()