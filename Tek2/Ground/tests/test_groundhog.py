#!/usr/bin/python3

from src.groundhog import display_res
from src.groundhog import get_data

def test_display_res():
    assert display_res(0.00, 0.00, 0.00) == None
