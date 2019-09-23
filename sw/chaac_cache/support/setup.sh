#!/bin/bash

# Make sure we're in the right directory
cd `git rev-parse --show-toplevel`/sw/chaac_cache

echo "pipenv setup"

# Temporary workaround. Getting hash errors when trying to install without --sequential
# also getting modules not found error when trying to install from pipfile after
# it's moved to /var :(

rm ./Pipfile
export PIPENV_VENV_IN_PROJECT=true; pipenv install --three
export PIPENV_VENV_IN_PROJECT=true; pipenv install requests pyyaml

echo "Remove old setup"
sudo rm -r /var/flaskapp/chaac_cache

bash ./support/update.sh

cd -