#!/bin/bash
# vi: set sw=4 ts=4 ai:
#
# Author : Ton Kersten
# Date   : 2023-06-10

# Run an Ansible playbook in the execution environment
# You need to install `ansible-navigator` for this.
#
# To share the local Vault Password file, the home
# directory is mounted on `/data` in the container.

# Define the Ansible configuration file
export ANSIBLE_CONFIG="ping/ansible.cfg"

# Navigator mode. stdout or interactive
MODE="interactive"
MODE="stdout"

ansible-navigator									\
	run ping/ping.yml								\
		--mode ${MODE}								\
		--eei localhost/ee_hvac_vault:1.2			\
		--pull-policy missing						\
		--eev ${HOME}:/data							\
		--vault-password-file /data/.VaultPassword	\
		--inventory ping_inventory

