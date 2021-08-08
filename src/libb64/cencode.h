/**************************************************************************************************************************************
  cencoder.h - c source to a base64 decoding algorithm implementation
  For RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields

  WiFiWebServer_RTL8720 is a library for the RTL8720DN, RTL8722DM and RTL8722CSM WiFi shields to run WebServer

  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer_RTL8720
  Licensed under MIT license

  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2021 Initial coding for Realtek RTL8720DN, RTL8722DM and RTL8722CSM
  1.0.1   K Hoang      07/08/2021 Fix version typo
 ***************************************************************************************************************************************/

#pragma once

// Reintroduce to prevent duplication compile error if other lib/core already has LIB64
// pragma once can't prevent that
#ifndef BASE64_CENCODE_H
#define BASE64_CENCODE_H

#define BASE64_CHARS_PER_LINE 72

#define base64_encode_expected_len_nonewlines(n) ((((4 * (n)) / 3) + 3) & ~3)
#define base64_encode_expected_len(n) \
       (base64_encode_expected_len_nonewlines(n) + ((n / ((BASE64_CHARS_PER_LINE * 3) / 4)) + 1))


#ifdef __cplusplus
  extern "C" {
#endif

typedef enum 
{
  step_A, 
  step_B, 
  step_C
} base64_encodestep;

typedef struct 
{
  base64_encodestep step;
  char result;
  int stepcount;
  int stepsnewline;
} base64_encodestate;

void base64_init_encodestate(base64_encodestate* state_in);
void base64_init_encodestate_nonewlines(base64_encodestate* state_in);

char base64_encode_value(char value_in);

int base64_encode_block(const char* plaintext_in, int length_in, char* code_out, base64_encodestate* state_in);

int base64_encode_blockend(char* code_out, base64_encodestate* state_in);

int base64_encode_chars(const char* plaintext_in, int length_in, char* code_out);

#ifdef __cplusplus
  } // extern "C"
#endif

#endif /* BASE64_CENCODE_H */

