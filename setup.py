from setuptools import setup
from setuptools import Extension

setup(
    name='hello-lib',
    version='0.0.1',
    ext_modules=[Extension('hello', ['hello.c'])],
)
