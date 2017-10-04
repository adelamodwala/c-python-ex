from distutils.core import setup, Extension
setup(name='log_consumer', version='1.0',  \
    ext_modules=[Extension('log_consumer', ['log_consumer/log_consumer_module.c'])])

