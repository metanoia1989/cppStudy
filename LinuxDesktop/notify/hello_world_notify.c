#include <libnotify/notify.h>

int main(int argc, char const *argv[])
{
    notify_init("你好啊，这是一则通知");
    NotifyNotification *Hello = notify_notification_new("你好啊，这是一则通知",
        "演示libnotify的C语言示例", "dialog-information");
    notify_notification_show(Hello, NULL);
    g_object_unref(G_OBJECT(Hello));
    notify_uninit();

    return 0;
}
