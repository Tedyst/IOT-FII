from django.contrib import admin
from .models import Device, Sensor, SensorData

admin.site.register(Device)
admin.site.register(Sensor)
admin.site.register(SensorData)