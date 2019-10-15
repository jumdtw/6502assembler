.lavel  lda $4016
        sta lavel    
        ora #%00001111
        jsr $8000
        rts
        rti