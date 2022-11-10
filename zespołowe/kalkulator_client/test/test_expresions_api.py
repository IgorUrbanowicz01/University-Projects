# coding: utf-8

"""
    Calculator - OpenAPI 3.0

    Calculator for simple arthmetic funcions  # noqa: E501

    OpenAPI spec version: 1.0.11
    Contact: igoor.urbanowicz@gmail.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""

from __future__ import absolute_import

import unittest

import swagger_client
from swagger_client.api.expresions_api import ExpresionsApi  # noqa: E501
from swagger_client.rest import ApiException


class TestExpresionsApi(unittest.TestCase):
    """ExpresionsApi unit test stubs"""

    def setUp(self):
        self.api = ExpresionsApi()  # noqa: E501

    def tearDown(self):
        pass

    def test_add_number(self):
        """Test case for add_number

        add number to acumulator  # noqa: E501
        """
        pass

    def test_clear_number(self):
        """Test case for clear_number

        clear number from acumulator  # noqa: E501
        """
        pass

    def test_div_number(self):
        """Test case for div_number

        sub number from acumulator  # noqa: E501
        """
        pass

    def test_get_acc(self):
        """Test case for get_acc

        get accumulator  # noqa: E501
        """
        pass

    def test_mul_number(self):
        """Test case for mul_number

        mul number from acumulator  # noqa: E501
        """
        pass

    def test_sub_number(self):
        """Test case for sub_number

        sub number from acumulator  # noqa: E501
        """
        pass


if __name__ == '__main__':
    unittest.main()
