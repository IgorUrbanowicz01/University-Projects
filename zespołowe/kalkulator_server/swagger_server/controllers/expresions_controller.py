import connexion
import six

from swagger_server.models.expresions import Expresions  # noqa: E501
from swagger_server.models.resoult import Resoult  # noqa: E501
from swagger_server import util


def add_number(body):  # noqa: E501
    """add number to acumulator

     # noqa: E501

    :param body: 
    :type body: dict | bytes

    :rtype: Expresions
    """
    if connexion.request.is_json:
        body = Expresions.from_dict(connexion.request.get_json())  # noqa: E501
    return Expresions(body.acc, body.exp, body.acc + body.num)  


def clear_number():  # noqa: E501
    """clear number from acumulator

     # noqa: E501


    :rtype: Resoult
    """
    return Resoult(0)


def div_number(body):  # noqa: E501
    """sub number from acumulator

     # noqa: E501

    :param body: 
    :type body: dict | bytes

    :rtype: Expresions
    """
    if connexion.request.is_json:
        body = Expresions.from_dict(connexion.request.get_json())  # noqa: E501
    return Expresions(body.acc, body.exp, body.acc / body.num)


def get_acc():  # noqa: E501
    """get accumulator

     # noqa: E501


    :rtype: Resoult
    """
    return body.acc


def mul_number(body):  # noqa: E501
    """mul number from acumulator

     # noqa: E501

    :param body: 
    :type body: dict | bytes

    :rtype: Expresions
    """
    if connexion.request.is_json:
        body = Expresions.from_dict(connexion.request.get_json())  # noqa: E501
    return Expresions(body.acc, body.exp, body.acc * body.num)


def sub_number(body):  # noqa: E501
    """sub number from acumulator

     # noqa: E501

    :param body: 
    :type body: dict | bytes

    :rtype: Expresions
    """
    if connexion.request.is_json:
        body = Expresions.from_dict(connexion.request.get_json())  # noqa: E501
    return Expresions(body.acc, body.exp, body.acc + body.num)