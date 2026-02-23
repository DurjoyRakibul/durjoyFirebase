# durjoyFirebase

Lightweight Firebase Realtime Database REST client for ESP8266.

## Features

- No official Firebase client required
- HTTPS REST API
- sendFloat() - overwrite value (PUT)
- Simple and minimal

## Installation

1. Download this repository as ZIP
2. Extract to Documents/Arduino/libraries/
3. Restart Arduino IDE
4. Include:

   #include <durjoyFirebase.h>

## Example

See examples/BasicExample

## Firebase Setup

1. Create Firebase project
2. Enable Realtime Database
3. Set temporary test rules:

{
  "rules": {
    ".read": true,
    ".write": true
  }
}

## Notes

- Uses client.setInsecure() for SSL
- Recommended for learning and small projects
- For production, certificate validation should be added
