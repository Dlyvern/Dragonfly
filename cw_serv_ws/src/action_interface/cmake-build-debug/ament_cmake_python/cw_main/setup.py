from setuptools import find_packages
from setuptools import setup

setup(
    name='cw_main',
    version='0.0.0',
    packages=find_packages(
        include=('cw_main', 'cw_main.*')),
)
