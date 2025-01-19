#include "mdev.h"
#include "mdev_bus.h"
#include "mdev_driver.h"

static int mdev_drv_probe(struct mdev_device *dev)
{
    pr_info("Mdev drv probe\n");
    return 0;
}

static void mdev_drv_remove(struct mdev_device *dev)
{
    pr_info("Mdev drv remove\n");
}

static struct mdev_driver mdev_drv = {
    .probe = mdev_drv_probe,
    .remove = mdev_drv_remove
};

int mdev_drv_init(void)
{
    int ret;

    mdev_drv.driver.bus = mdev_get_bus_type();
    ret = driver_register(&mdev_drv.driver);
    if (ret != 0) {
        pr_err("Drv register fail\n");
        return ret;
    }

    return 0;
}

void mdev_drv_uninit(void) 
{
    driver_unregister(&mdev_drv.driver);
}

MODULE_LICENSE("GPL");
