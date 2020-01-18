.NMI    ldx $206
    lda [#$00]
    pha
    pla
    sta $209
    lda $209
    pha
    lda #$0
    pha
    sec
    pla
    sta $0
    pla
    sbc $0
    bne 25769_set_1
.25769_set_0    lda #$0
    jmp 25769_sete_end
.25769_set_1    lda #$1
.25769_sete_end    pha
    pla
    sta $0
    lda $0
    beq  25682_IF_jmp_end
    jmp 25682_if_execute
.25682_IF_jmp_end    jmp 25682end
.25682_if_execute    ldx $206
    lda [#$00]
    pha
    lda #$1
    pha
    sec
    pla
    sta $0
    pla
    sbc $0
    pha
    pla
    ldx $206
    sta [#$00]
    lda #$1
    pha
    pla
    rti
.25682end    lda #$0
    lda $207
    pha
    pla
    sta $0
    ldx $0
    lda [#$700]
    pha
    pla
    sta $4015
    lda $207
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $207
    lda $207
    pha
    pla
    sta $0
    ldx $0
    lda [#$700]
    pha
    pla
    sta $4000
    lda $207
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $207
    lda $207
    pha
    pla
    sta $0
    ldx $0
    lda [#$700]
    pha
    pla
    sta $4002
    lda $207
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $207
    lda $207
    pha
    pla
    sta $0
    ldx $0
    lda [#$700]
    pha
    pla
    sta $4003
    lda $207
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $207
    lda $207
    pha
    pla
    sta $0
    ldx $0
    lda [#$700]
    pha
    pla
    sta $4006
    lda $207
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $207
    lda $207
    pha
    pla
    sta $0
    ldx $0
    lda [#$700]
    pha
    pla
    sta $400a
    lda $207
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $207
    lda $207
    pha
    pla
    sta $0
    ldx $0
    lda [#$700]
    pha
    pla
    sta $1
    lda $207
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $207
    lda $207
    pha
    lda $208
    pha
    sec
    pla
    sta $0
    pla
    sbc $0
    beq 25943_set_1
.25943_set_0    lda #$0
    jmp 25943_sete_end
.25943_set_1    lda #$1
.25943_sete_end    pha
    pla
    sta $0
    lda $0
    beq  25856_IF_jmp_end
    jmp 25856_if_execute
.25856_IF_jmp_end    jmp 25856end
.25856_if_execute    lda $20a
    pha
    pla
    sta $0
    lda $0
    beq  26030_IF_jmp_end
    jmp 26030_if_execute
.26030_IF_jmp_end    jmp 26030end
.26030_if_execute    lda #$0
    pha
    pla
    sta $20a
    lda #$1
    pha
    pla
    sta $20b
    lda #$0
    pha
    pla
    sta $207
    lda #$54
    pha
    pla
    sta $208
    lda #$7
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$1c
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$1c
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$0
    pha
    lda #$1c
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$1c
    pha
    lda #$0
    pha
    lda #$af
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$16
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$86
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$18
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$86
    pha
    lda #$0
    pha
    lda #$a9
    pha
    lda #$0
    pha
    lda #$10
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$18
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$7e
    pha
    lda #$86
    pha
    lda #$2a
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$19
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$6a
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$19
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$86
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$19
    pha
    lda #$54
    pha
    pla
    sta $0
    ldx $0
    dex
.26117assgin_array    pla
    sta [#$700]
    dex
    bne 26117assgin_array
    pla
    sta $700
    lda #$1
    pha
    pla
    rti
.26030end    lda #$0
    lda $20b
    pha
    pla
    sta $0
    lda $0
    beq  26204_IF_jmp_end
    jmp 26204_if_execute
.26204_IF_jmp_end    jmp 26204end
.26204_if_execute    lda #$0
    pha
    pla
    sta $20b
    lda #$1
    pha
    pla
    sta $20c
    lda #$0
    pha
    pla
    sta $207
    lda #$62
    pha
    pla
    sta $208
    lda #$1
    pha
    lda #$af
    pha
    lda #$96
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$19
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$a9
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$f
    pha
    lda #$1
    pha
    lda #$ad
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$30
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$11
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$26
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$1c
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$77
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$0
    pha
    lda #$12
    pha
    lda #$5
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$12
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$77
    pha
    lda #$12
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$12
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$96
    pha
    lda #$0
    pha
    lda #$a9
    pha
    lda #$0
    pha
    lda #$1c
    pha
    lda #$62
    pha
    pla
    sta $0
    ldx $0
    dex
.26291assgin_array    pla
    sta [#$700]
    dex
    bne 26291assgin_array
    pla
    sta $700
    lda #$1
    pha
    pla
    rti
.26204end    lda #$0
    lda $20c
    pha
    pla
    sta $0
    lda $0
    beq  26378_IF_jmp_end
    jmp 26378_if_execute
.26378_IF_jmp_end    jmp 26378end
.26378_if_execute    lda #$0
    pha
    pla
    sta $20c
    lda #$1
    pha
    pla
    sta $20d
    lda #$0
    pha
    pla
    sta $207
    lda #$69
    pha
    pla
    sta $208
    lda #$7
    pha
    lda #$a7
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$12
    pha
    lda #$7
    pha
    lda #$a7
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$12
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$10
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$1c
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$1c
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$77
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$12
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$12
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$b3
    pha
    lda #$0
    pha
    lda #$12
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$b3
    pha
    lda #$0
    pha
    lda #$10
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$86
    pha
    lda #$0
    pha
    lda #$b3
    pha
    lda #$0
    pha
    lda #$1c
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$1a
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$1a
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$0
    pha
    lda #$1a
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$0
    pha
    lda #$24
    pha
    lda #$0
    pha
    lda #$af
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$18
    pha
    lda #$69
    pha
    pla
    sta $0
    ldx $0
    dex
.26465assgin_array    pla
    sta [#$700]
    dex
    bne 26465assgin_array
    pla
    sta $700
    lda #$1
    pha
    pla
    rti
.26378end    lda #$0
    lda $20d
    pha
    pla
    sta $0
    lda $0
    beq  26552_IF_jmp_end
    jmp 26552_if_execute
.26552_IF_jmp_end    jmp 26552end
.26552_if_execute    lda #$0
    pha
    pla
    sta $20d
    lda #$1
    pha
    pla
    sta $20e
    lda #$0
    pha
    pla
    sta $207
    lda #$70
    pha
    pla
    sta $208
    lda #$7
    pha
    lda #$a7
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$86
    pha
    lda #$a9
    pha
    lda #$e
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$86
    pha
    lda #$a9
    pha
    lda #$14
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$14
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$86
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$a9
    pha
    lda #$8e
    pha
    lda #$28
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$a9
    pha
    lda #$8e
    pha
    lda #$e
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$a9
    pha
    lda #$8e
    pha
    lda #$e
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$12
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$77
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$10
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$25
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$0
    pha
    lda #$10
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$0
    pha
    lda #$10
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$12
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$10
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$7e
    pha
    lda #$0
    pha
    lda #$28
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$6a
    pha
    lda #$0
    pha
    lda #$86
    pha
    lda #$0
    pha
    lda #$32
    pha
    lda #$70
    pha
    pla
    sta $0
    ldx $0
    dex
.26639assgin_array    pla
    sta [#$700]
    dex
    bne 26639assgin_array
    pla
    sta $700
    lda #$1
    pha
    pla
    rti
.26552end    lda #$0
    lda $20e
    pha
    pla
    sta $0
    lda $0
    beq  26726_IF_jmp_end
    jmp 26726_if_execute
.26726_IF_jmp_end    jmp 26726end
.26726_if_execute    lda #$0
    pha
    pla
    sta $20e
    lda #$1
    pha
    pla
    sta $20f
    lda #$0
    pha
    pla
    sta $207
    lda #$62
    pha
    pla
    sta $208
    lda #$0
    pha
    lda #$af
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$12
    pha
    lda #$7
    pha
    lda #$ab
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$86
    pha
    lda #$a9
    pha
    lda #$d
    pha
    lda #$7
    pha
    lda #$ab
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$86
    pha
    lda #$a9
    pha
    lda #$d
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$77
    pha
    lda #$0
    pha
    lda #$a9
    pha
    lda #$0
    pha
    lda #$d
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$86
    pha
    lda #$a9
    pha
    lda #$d
    pha
    lda #$0
    pha
    lda #$af
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$d
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$86
    pha
    lda #$a9
    pha
    lda #$18
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$8e
    pha
    lda #$a9
    pha
    lda #$1a
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$1a
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$8e
    pha
    lda #$a9
    pha
    lda #$1a
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$1a
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$b3
    pha
    lda #$3c
    pha
    lda #$0
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$b3
    pha
    lda #$32
    pha
    lda #$62
    pha
    pla
    sta $0
    ldx $0
    dex
.26813assgin_array    pla
    sta [#$700]
    dex
    bne 26813assgin_array
    pla
    sta $700
    lda #$1
    pha
    pla
    rti
.26726end    lda #$0
    lda $20f
    pha
    pla
    sta $0
    lda $0
    beq  26900_IF_jmp_end
    jmp 26900_if_execute
.26900_IF_jmp_end    jmp 26900end
.26900_if_execute    lda #$0
    pha
    pla
    sta $2000
    lda #$0
    pha
    pla
    sta $4015
.26900end    lda #$0
.25856end    lda #$0
    lda #$1
    pha
    pla
    rti

.main    lda #$7
    pha
    pla
    sta $4015
    lda #$af
    pha
    pla
    sta $4000
    lda #$0
    pha
    pla
    sta $4001
    lda #$af
    pha
    pla
    sta $4004
    lda #$0
    pha
    pla
    sta $4005
    lda #$0
    pha
    pla
    sta $4007
    lda #$ff
    pha
    pla
    sta $4008
    lda #$0
    pha
    pla
    sta $400b
    lda #$1
    pha
    pla
    sta $206
    lda #$14
    pha
    pla
    ldx $206
    sta [#$00]
    lda #$0
    pha
    pla
    sta $207
    lda #$69
    pha
    pla
    sta $208
    lda #$0
    pha
    pla
    sta $209
    lda #$1
    pha
    pla
    sta $20a
    lda #$0
    pha
    pla
    sta $20b
    lda #$0
    pha
    pla
    sta $20c
    lda #$0
    pha
    pla
    sta $20d
    lda #$0
    pha
    pla
    sta $20e
    lda #$0
    pha
    pla
    sta $20f
    lda #$3
    pha
    lda #$af
    pha
    lda #$77
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$0
    pha
    lda #$13
    pha
    lda #$5
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$13
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$96
    pha
    lda #$77
    pha
    lda #$13
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$13
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$96
    pha
    lda #$0
    pha
    lda #$b3
    pha
    lda #$0
    pha
    lda #$19
    pha
    lda #$7
    pha
    lda #$a7
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$13
    pha
    lda #$7
    pha
    lda #$a7
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$13
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$11
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$54
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$19
    pha
    lda #$7
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$77
    pha
    lda #$96
    pha
    lda #$1b
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$77
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$13
    pha
    lda #$1
    pha
    lda #$af
    pha
    lda #$70
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$13
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$64
    pha
    lda #$0
    pha
    lda #$b3
    pha
    lda #$0
    pha
    lda #$13
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$59
    pha
    lda #$0
    pha
    lda #$b3
    pha
    lda #$0
    pha
    lda #$11
    pha
    lda #$3
    pha
    lda #$af
    pha
    lda #$86
    pha
    lda #$0
    pha
    lda #$b3
    pha
    lda #$0
    pha
    lda #$1e
    pha
    lda #$69
    pha
    pla
    sta $0
    ldx $0
    dex
.26987assgin_array    pla
    sta [#$700]
    dex
    bne 26987assgin_array
    pla
    sta $700
    lda #$80
    pha
    pla
    sta $2000
.27074_LOOP    jmp 27074_LOOP
