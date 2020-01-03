.main111    pha  
            pla
            clc
            sec
            bne main111
            beq main111
            adc $20
            sbc $10
            bne main222
            beq main222
            pha  
            pla
            clc
            sec
.main222    adc $20
            sbc $10


