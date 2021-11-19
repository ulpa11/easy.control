from rest_framework import serializers
from .models import DeviceStatus,Testing

class DeviceSerializers(serializers.ModelSerializer):
    class Meta:
        model=DeviceStatus
        fields="__all__"
class TestingSerializers(serializers.ModelSerializer):
    class Meta:
        model=Testing
        fields="__all__"