# coding: utf-8

from __future__ import absolute_import

from flask import json
from six import BytesIO

from swagger_server.models.expresions import Expresions  # noqa: E501
from swagger_server.models.resoult import Resoult  # noqa: E501
from swagger_server.test import BaseTestCase


class TestExpresionsController(BaseTestCase):
    """ExpresionsController integration test stubs"""

    def test_add_number(self):
        """Test case for add_number

        add number to acumulator
        """
        body = Expresions()
        response = self.client.open(
            '/expresions/add',
            method='PUT',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_clear_number(self):
        """Test case for clear_number

        clear number from acumulator
        """
        response = self.client.open(
            '/expresions/clear',
            method='DELETE')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_div_number(self):
        """Test case for div_number

        sub number from acumulator
        """
        body = Expresions()
        response = self.client.open(
            '/expresions/div',
            method='PUT',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_get_acc(self):
        """Test case for get_acc

        get accumulator
        """
        response = self.client.open(
            '/expresions/get',
            method='GET')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_mul_number(self):
        """Test case for mul_number

        mul number from acumulator
        """
        body = Expresions()
        response = self.client.open(
            '/expresions/mul',
            method='PUT',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_sub_number(self):
        """Test case for sub_number

        sub number from acumulator
        """
        body = Expresions()
        response = self.client.open(
            '/expresions/sub',
            method='PUT',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))


if __name__ == '__main__':
    import unittest
    unittest.main()
