from django.shortcuts import render
from django.http import  HttpResponse
from json import dumps
# Create your views here.
from .serializers import  DeviceSerializers,TestingSerializers
from .models import DeviceStatus,Testing
from rest_framework.response import Response
from rest_framework import viewsets



def index(request):
    data=DeviceStatus.objects.last()
    return render(request, 'index.html', {'data': data})

class DeviceApiViewSet(viewsets.ModelViewSet):
    queryset=DeviceStatus.objects.all()
    serializer_class=DeviceSerializers
    def perform_update(self, serializer):
        # Save with the new value for the target model fields
        user = self.request.user
        userid = str(user.id)
        serializer.save(stu_enrolled_classes=userid)
class TestingViewSet(viewsets.ModelViewSet):
    queryset=Testing.objects.all()
    serializer_class=TestingSerializers

    def perform_update(self, serializer):
        # Save with the new value for the target model fields
        user = self.request.user
        userid = str(user.id)
        serializer.save(stu_enrolled_classes=userid)
