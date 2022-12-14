# swagger-client
Calculator for simple arthmetic funcions

This Python package is automatically generated by the [Swagger Codegen](https://github.com/swagger-api/swagger-codegen) project:

- API version: 1.0.11
- Package version: 1.0.0
- Build package: io.swagger.codegen.v3.generators.python.PythonClientCodegen

## Requirements.

Python 2.7 and 3.4+

## Installation & Usage
### pip install

If the python package is hosted on Github, you can install directly from Github

```sh
pip install git+https://github.com/GIT_USER_ID/GIT_REPO_ID.git
```
(you may need to run `pip` with root permission: `sudo pip install git+https://github.com/GIT_USER_ID/GIT_REPO_ID.git`)

Then import the package:
```python
import swagger_client 
```

### Setuptools

Install via [Setuptools](http://pypi.python.org/pypi/setuptools).

```sh
python setup.py install --user
```
(or `sudo python setup.py install` to install the package for all users)

Then import the package:
```python
import swagger_client
```

## Getting Started

Please follow the [installation procedure](#installation--usage) and then run the following:

```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi(swagger_client.ApiClient(configuration))
body = swagger_client.Expresions() # Expresions | 

try:
    # add number to acumulator
    api_response = api_instance.add_number(body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->add_number: %s\n" % e)

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi(swagger_client.ApiClient(configuration))

try:
    # clear number from acumulator
    api_response = api_instance.clear_number()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->clear_number: %s\n" % e)

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi(swagger_client.ApiClient(configuration))
body = swagger_client.Expresions() # Expresions | 

try:
    # sub number from acumulator
    api_response = api_instance.div_number(body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->div_number: %s\n" % e)

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi(swagger_client.ApiClient(configuration))

try:
    # get accumulator
    api_response = api_instance.get_acc()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->get_acc: %s\n" % e)

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi(swagger_client.ApiClient(configuration))
body = swagger_client.Expresions() # Expresions | 

try:
    # mul number from acumulator
    api_response = api_instance.mul_number(body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->mul_number: %s\n" % e)

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi(swagger_client.ApiClient(configuration))
body = swagger_client.Expresions() # Expresions | 

try:
    # sub number from acumulator
    api_response = api_instance.sub_number(body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->sub_number: %s\n" % e)
```

## Documentation for API Endpoints

All URIs are relative to *https://localhost:8080*

Class | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*ExpresionsApi* | [**add_number**](docs/ExpresionsApi.md#add_number) | **PUT** /expresions/add | add number to acumulator
*ExpresionsApi* | [**clear_number**](docs/ExpresionsApi.md#clear_number) | **DELETE** /expresions/clear | clear number from acumulator
*ExpresionsApi* | [**div_number**](docs/ExpresionsApi.md#div_number) | **PUT** /expresions/div | sub number from acumulator
*ExpresionsApi* | [**get_acc**](docs/ExpresionsApi.md#get_acc) | **GET** /expresions/get | get accumulator
*ExpresionsApi* | [**mul_number**](docs/ExpresionsApi.md#mul_number) | **PUT** /expresions/mul | mul number from acumulator
*ExpresionsApi* | [**sub_number**](docs/ExpresionsApi.md#sub_number) | **PUT** /expresions/sub | sub number from acumulator

## Documentation For Models

 - [Expresions](docs/Expresions.md)
 - [Resoult](docs/Resoult.md)

## Documentation For Authorization

 All endpoints do not require authorization.


## Author

igoor.urbanowicz@gmail.com
