# swagger_client.ExpresionsApi

All URIs are relative to *https://localhost:8080*

Method | HTTP request | Description
------------- | ------------- | -------------
[**add_number**](ExpresionsApi.md#add_number) | **PUT** /expresions/add | add number to acumulator
[**clear_number**](ExpresionsApi.md#clear_number) | **DELETE** /expresions/clear | clear number from acumulator
[**div_number**](ExpresionsApi.md#div_number) | **PUT** /expresions/div | sub number from acumulator
[**get_acc**](ExpresionsApi.md#get_acc) | **GET** /expresions/get | get accumulator
[**mul_number**](ExpresionsApi.md#mul_number) | **PUT** /expresions/mul | mul number from acumulator
[**sub_number**](ExpresionsApi.md#sub_number) | **PUT** /expresions/sub | sub number from acumulator

# **add_number**
> Expresions add_number(body)

add number to acumulator

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi()
body = swagger_client.Expresions() # Expresions | 

try:
    # add number to acumulator
    api_response = api_instance.add_number(body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->add_number: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**Expresions**](Expresions.md)|  | 

### Return type

[**Expresions**](Expresions.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **clear_number**
> Resoult clear_number()

clear number from acumulator

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi()

try:
    # clear number from acumulator
    api_response = api_instance.clear_number()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->clear_number: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**Resoult**](Resoult.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **div_number**
> Expresions div_number(body)

sub number from acumulator

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi()
body = swagger_client.Expresions() # Expresions | 

try:
    # sub number from acumulator
    api_response = api_instance.div_number(body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->div_number: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**Expresions**](Expresions.md)|  | 

### Return type

[**Expresions**](Expresions.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **get_acc**
> Resoult get_acc()

get accumulator

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi()

try:
    # get accumulator
    api_response = api_instance.get_acc()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->get_acc: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**Resoult**](Resoult.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **mul_number**
> Expresions mul_number(body)

mul number from acumulator

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi()
body = swagger_client.Expresions() # Expresions | 

try:
    # mul number from acumulator
    api_response = api_instance.mul_number(body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->mul_number: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**Expresions**](Expresions.md)|  | 

### Return type

[**Expresions**](Expresions.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **sub_number**
> Expresions sub_number(body)

sub number from acumulator

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.ExpresionsApi()
body = swagger_client.Expresions() # Expresions | 

try:
    # sub number from acumulator
    api_response = api_instance.sub_number(body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling ExpresionsApi->sub_number: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**Expresions**](Expresions.md)|  | 

### Return type

[**Expresions**](Expresions.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

