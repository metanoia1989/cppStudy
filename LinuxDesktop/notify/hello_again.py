#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from gi.repository import Notify

Notify.init("星火商店")

body = '''
如题，星火应用商店官网初代来了！
最后奉上网址：https://spark-app.tk/（该域名非正式域名，现在测试用。）
因为这是我今天刚做的网站，所以网站可能存在一些问题，大家可以提出意见。
'''
notify = Notify.Notification.new("欢迎访问呢星火商店", body)
notify.show()
