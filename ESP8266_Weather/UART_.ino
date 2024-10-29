
extern espPacket_ espPacket;

void send_packet() {
 strncpy(espPacket.uartKey, "ESP", 3);  // Präfix zur Überprüfung
 Serial.write((uint8_t*)&espPacket, sizeof(espPacket));
}
