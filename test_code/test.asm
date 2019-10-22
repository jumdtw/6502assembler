.reset          lda #%00000001
                sta $4015
                ;oppai
                lda #%10100001                        
                sta $4000	                       
                lda #$00                              
                sta $4001	                       
;              unnschi
                lda #$ca
                sta $4002
                lda #$00     
                sta $4003

