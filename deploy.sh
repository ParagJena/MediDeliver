#!/bin/bash

build_project() {
    echo "Building MediDeliver..."
    make clean
    make
}

create_backup() {
    mkdir -p backups
    timestamp=$(date +"%Y%m%d_%H%M%S")
    tar -czf "backups/medideliver_${timestamp}.tar.gz" include src data Makefile
    echo "Backup created successfully."
}

run_project() {
    echo "Starting MediDeliver..."
    make run
}

if [ "$1" = "development" ]; then
    build_project
    run_project
elif [ "$1" = "backup" ]; then
    create_backup
elif [ "$1" = "production" ]; then
    build_project
    create_backup
    echo "Production build completed."
else
    echo "Usage: ./deploy.sh development"
    echo "Usage: ./deploy.sh backup"
    echo "Usage: ./deploy.sh production"
fi
