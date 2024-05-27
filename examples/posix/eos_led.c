/* include ------------------------------------------------------------------ */
#include "eos_led.h"
#include "eventos.h"
#include "event_def.h"
#include <stdio.h>

#if (EOS_USE_SM_MODE != 0)
/* data structure ----------------------------------------------------------- */
typedef struct eos_led_tag {
    eos_sm_t super;

    eos_bool_t status;
} eos_led_t;

static eos_led_t led;

/* static state function ---------------------------------------------------- */
static eos_ret_t state_init(eos_led_t* const me, eos_event_t const* const e);
static eos_ret_t state_on(eos_led_t* const me, eos_event_t const* const e);
static eos_ret_t state_off(eos_led_t* const me, eos_event_t const* const e);

/* api ---------------------------------------------------- */
void eos_led_init(void)
{
    eos_sm_init(&led.super, 1, 0);
    eos_sm_start(&led.super, EOS_STATE_CAST(state_init));

    led.status = 0;
}

/* static state function ---------------------------------------------------- */
static eos_ret_t state_init(eos_led_t* const me, eos_event_t const* const e)
{
#if (EOS_USE_PUB_SUB != 0)
    EOS_EVENT_SUB(Event_Time_500ms);
#endif
#if (EOS_USE_TIME_EVENT != 0)
    eos_event_pub_period(Event_Time_500ms, 500);
#endif

    return EOS_TRAN(state_off);
}

static eos_ret_t state_on(eos_led_t* const me, eos_event_t const* const e)
{
    switch (e->topic)
    {
    case Event_Enter:
        printf("State On!\n");
        me->status = 1;
        return EOS_Ret_Handled;

    case Event_Time_500ms:
        return EOS_TRAN(state_off);

    default:
        return EOS_SUPER(eos_state_top);
    }
}

static eos_ret_t state_off(eos_led_t* const me, eos_event_t const* const e)
{
    switch (e->topic)
    {
    case Event_Enter:
        printf("State Off!\n");
        me->status = 0;
        return EOS_Ret_Handled;

    case Event_Time_500ms:
        return EOS_TRAN(state_on);

    default:
        return EOS_SUPER(eos_state_top);
    }
}
#endif

/* data structure ----------------------------------------------------------- */
typedef struct eos_reactor_led_tag {
    eos_reactor_t super;
    eos_u8_t      status;
} eos_reactor_led_t;

eos_reactor_led_t actor_led;

/* static event handler ----------------------------------------------------- */
static void led_e_handler(eos_reactor_led_t* const me, eos_event_t const* const e);

/* api ---------------------------------------------------- */
void eos_reactor_led_init(void)
{
    eos_reactor_init(&actor_led.super, 2, EOS_NULL);
    eos_reactor_start(&actor_led.super, EOS_HANDLER_CAST(led_e_handler));

    actor_led.status = 0;

#if (EOS_USE_PUB_SUB != 0)
    eos_event_sub(( eos_actor_t* )(&actor_led), Event_Time_1000ms);
#endif
#if (EOS_USE_TIME_EVENT != 0)
    eos_event_pub_period(Event_Time_1000ms, 1000);
#endif
}

/* static state function ---------------------------------------------------- */
static void led_e_handler(eos_reactor_led_t* const me, eos_event_t const* const e)
{
    if (e->topic == Event_Time_1000ms)
    {
        me->status = (me->status == 0) ? 1 : 0;
        printf("me->status %d!\n", me->status);
    }
}
