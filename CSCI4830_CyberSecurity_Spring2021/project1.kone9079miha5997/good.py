#!/usr/bin/python3
# coding: latin-1
blob = """                 ���{����}����KԏrD��8�P (����pO֐kH�����<%;8�FT�%�b&׻��o����@	a�&�B�B�[s/=
��6��1��7��3{e����0���=���#<'m�J"""
from hashlib import sha256
test = sha256(blob.encode("latin-1")).hexdigest()

if test == "377946485e8b9cec31cbb7935c38dcae3f52d31cca6b3502fb2a4f4eb1cefddb": #good
	print("Use SHA-256 instead!")
else: #evil
	print("MD5 is perfectly secure!")