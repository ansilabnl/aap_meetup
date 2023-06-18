#!/bin/bash
# vi: set sw=4 ts=4 ai:
#
# Author : Ton Kersten
# Date   : 2023-06-10

# Use `curl` to run a template on the AAP server.
# In the template, tick the "Provisioning Callbacks"
# box, generate a random key and put that in the
# "Host Config Key" field.

AAP_HOST="https://aap.ansilab.nl"
KEY="q0jUeNCqP2PPZh8jIGdSCHYHCUgZuA"
URL="${AAP_HOST}/api/v2/job_templates/11/callback/"

curl -k -f -i										\
	-H 'Content-Type:application/json'				\
	-XPOST -d "{\"host_config_key\": \"${KEY}\"}"	\
	${URL}

# Alternative:
#	/usr/share/awx/request_tower_configuration.sh	\
#		-s ${AAP_HOST}								\
#		-k											\
#		-c ${KEY}									\
#		-t 11

