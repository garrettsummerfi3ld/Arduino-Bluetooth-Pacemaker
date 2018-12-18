#!/usr/bin/bash
echo "Running keyserver setup script..."
sleep 5
echo "__        __             _ _ _                               _ "
echo "\ \      / /__ _ __   __| | (_)_ __   __ _    __ _ _ __   __| |"
echo " \ \ /\ / / _ \ '_ \ / _  | | | |_ \ / _  |  / _  |  _ \ / _  |"
echo "  \ V  V /  __/ | | | (_| | | | | | | (_| | | (_| | | | | (_| |"
echo "   \_/\_/ \___|_| |_|\__,_|_|_|_| |_|\__, |  \__,_|_| |_|\__,_|"
echo "                                     |___/                     "
echo " _   _       _   _        ____             _                   "
echo "| | | | __ _| |_(_) ___  |  _ \  _____   _(_) ___ ___  ___     "
echo "| |_| |/ _  | __| |/ __| | | | |/ _ \ \ / / |/ __/ _ \/ __|    "
echo "|  _  | (_| | |_| | (__  | |_| |  __/\ V /| | (_|  __/\__ \    "
echo "|_| |_|\__,_|\__|_|\___| |____/ \___| \_/ |_|\___\___||___/    "
echo "W E L C O M E"

echo "Current login user: $(whoami)"
echo "Requesting root access..."
[ "$UID" -eq 0 ] || exec sudo "$0" "$@"

echo "Installing dependencies..."
apt install openssl

echo "Creating directory for keys..."
mkdir RSAKeys && cd RSAKeys

echo "Generating keys for CSRs..."
openssl req \
       -newkey rsa:2048 -nodes -keyout whkeyserver.key \
       -out whkeyserver.csr

echo "Creating certificates from the generated private keys and CSR..."
openssl x509 \
       -signkey whkeyserver.key \
       -in whkeyserver.csr \
       -req -days 365 -out whkeyserver.crt

echo "Verifying private keys matching the certificates and CSR"
openssl rsa -noout -modulus -in domain.key | openssl md5
openssl x509 -noout -modulus -in domain.crt | openssl md5
openssl req -noout -modulus -in domain.csr | openssl md5