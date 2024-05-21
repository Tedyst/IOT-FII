from rest_framework import serializers

from .models import Device, Sensor, SensorData

class SensorDataSerializer(serializers.ModelSerializer):
    class Meta:
        model = SensorData
        fields = '__all__'

class SensorSerializer(serializers.ModelSerializer):
    data = SensorDataSerializer(many=True, read_only=True)

    class Meta:
        model = Sensor
        fields = '__all__'

class DeviceSerializer(serializers.ModelSerializer):
    sensors = SensorSerializer(many=True, read_only=True)

    class Meta:
        model = Device
        fields = '__all__' 
