                lda $4015		
                ora #%00000111	
                sta $4015  

                lda #%10111101 
                sta $4000		
                lda #$00     
                sta $4001	    

                lda #%10111101  
                sta $4004		
                lda #$00        
                sta $4005	    

.sound          lda #$9f    
                sta $4002   
                lda #%00000000     
                sta $4003


                jmp delay_30

.lala           lda #$70    
                sta $4002   
                lda #%00000000     
                sta $4003


.delay_30       lda #$30
                sta $0
                dec $0
                lda $0
                beq #$fa
                jmp lala