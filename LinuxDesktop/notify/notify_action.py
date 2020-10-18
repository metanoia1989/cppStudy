#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from gi.repository import Notify

Notify.init("App")

def action_callback_func():
    print("回调触发")
    
notification = Notify.Notification.new("Hi!")
notification.add_action(
    "回复",
    "回复消息",
    action_callback_func,
    None
)

# 清除所有的action
# notification.clear_action()
notification.show()