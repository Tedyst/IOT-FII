from django.shortcuts import render
from rest_framework import viewsets

from .models import Device, Sensor, SensorData

from .serializers import DeviceSerializer, SensorSerializer, SensorDataSerializer

class DeviceViewSet(viewsets.ModelViewSet):
    queryset = Device.objects.all()
    serializer_class = DeviceSerializer

class SensorViewSet(viewsets.ModelViewSet):
    queryset = Sensor.objects.all()
    serializer_class = SensorSerializer

class SensorDataViewSet(viewsets.ModelViewSet):
    queryset = SensorData.objects.all()
    serializer_class = SensorDataSerializer

def devices(request):
    devices = Device.objects.all()
    return render(request, 'index.html', {'devices': devices})