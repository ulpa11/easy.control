from django.db import models

# Create your models here.
#{ id: 0, name: 'light', room: 'living room', state: 1 }
class DeviceStatus(models.Model):
    device_id=models.IntegerField()
    device_name=models.CharField(max_length=200)
    device_room=models.CharField(max_length=200)
    device_status=models.IntegerField()
    def __str__(self):
        return self.device_name
class Testing(models.Model):
    name=models.CharField(max_length=200)
