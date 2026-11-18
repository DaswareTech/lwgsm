/**
 * \file            lwgsm_timing.h
 * \brief           Points of the AT traffic an application can timestamp
 */
#ifndef LWGSM_HDR_TIMING_H
#define LWGSM_HDR_TIMING_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
    LWGSM_TIMING_DATA_IND,                      /*!< The modem announced buffered data (+CADATAIND / +CAURC) */
    LWGSM_TIMING_RECV_DATA,                     /*!< A CARECV response carries data */
    LWGSM_TIMING_RECV_EMPTY,                    /*!< A CARECV response is empty */
    LWGSM_TIMING_SEND_START,                    /*!< AT+CASEND issued for a chunk */
    LWGSM_TIMING_SEND_DONE,                     /*!< The modem took a chunk (OK after its data) */
} lwgsm_timing_point_t;

/**
 * \brief           Called at each point from the lwgsm threads. Weak and empty here: an application that wants to
 *                  timestamp the AT traffic defines its own, which must return at once.
 */
void lwgsm_timing_mark(lwgsm_timing_point_t point);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWGSM_HDR_TIMING_H */
