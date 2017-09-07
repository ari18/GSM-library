#include "SIMCOM.h"

bool SIMCOM::atSetModeGetTimestamp(bool mode) {
  const __FlashStringHelper *command = F("AT+CLTS=%d\r");
  char buffer[12];

  sprintf_P(buffer, (const char*)command, mode);

  dte->clearReceivedBuffer();
  if (!dte->ATCommand(buffer)) return false;
  if (!dte->ATResponseOk()) return false;
  this->allowGetTimestamp = mode;
  return true;
}

SIMCOM::SIMCOM(DTE &dte) {
  this->dte = &dte;
}
