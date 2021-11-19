from django.contrib import admin
from django.urls import path ,include
from . import  views
from rest_framework.routers import DefaultRouter
router=DefaultRouter()
router.register("DeviceApi",views.DeviceApiViewSet,basename="DeviceApi")
router.register("Testing",views.TestingViewSet,basename="TestingApi")
urlpatterns = [
    path('',views.index,name="index"),
    path("deviceapi/",include(router.urls)),


]
