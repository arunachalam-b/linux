/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2018, Red Hat, Inc.
 */

#ifndef SELFTEST_KVM_EVMCS_H
#define SELFTEST_KVM_EVMCS_H

#include <stdint.h>
#include "hyperv.h"
#include "vmx.h"

#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define EVMCS_VERSION 1

extern bool enable_evmcs;

struct hv_enlightened_vmcs {
	u32 revision_id;
	u32 abort;

	u16 host_es_selector;
	u16 host_cs_selector;
	u16 host_ss_selector;
	u16 host_ds_selector;
	u16 host_fs_selector;
	u16 host_gs_selector;
	u16 host_tr_selector;

	u16 padding16_1;

	u64 host_ia32_pat;
	u64 host_ia32_efer;

	u64 host_cr0;
	u64 host_cr3;
	u64 host_cr4;

	u64 host_ia32_sysenter_esp;
	u64 host_ia32_sysenter_eip;
	u64 host_rip;
	u32 host_ia32_sysenter_cs;

	u32 pin_based_vm_exec_control;
	u32 vm_exit_controls;
	u32 secondary_vm_exec_control;

	u64 io_bitmap_a;
	u64 io_bitmap_b;
	u64 msr_bitmap;

	u16 guest_es_selector;
	u16 guest_cs_selector;
	u16 guest_ss_selector;
	u16 guest_ds_selector;
	u16 guest_fs_selector;
	u16 guest_gs_selector;
	u16 guest_ldtr_selector;
	u16 guest_tr_selector;

	u32 guest_es_limit;
	u32 guest_cs_limit;
	u32 guest_ss_limit;
	u32 guest_ds_limit;
	u32 guest_fs_limit;
	u32 guest_gs_limit;
	u32 guest_ldtr_limit;
	u32 guest_tr_limit;
	u32 guest_gdtr_limit;
	u32 guest_idtr_limit;

	u32 guest_es_ar_bytes;
	u32 guest_cs_ar_bytes;
	u32 guest_ss_ar_bytes;
	u32 guest_ds_ar_bytes;
	u32 guest_fs_ar_bytes;
	u32 guest_gs_ar_bytes;
	u32 guest_ldtr_ar_bytes;
	u32 guest_tr_ar_bytes;

	u64 guest_es_base;
	u64 guest_cs_base;
	u64 guest_ss_base;
	u64 guest_ds_base;
	u64 guest_fs_base;
	u64 guest_gs_base;
	u64 guest_ldtr_base;
	u64 guest_tr_base;
	u64 guest_gdtr_base;
	u64 guest_idtr_base;

	u64 padding64_1[3];

	u64 vm_exit_msr_store_addr;
	u64 vm_exit_msr_load_addr;
	u64 vm_entry_msr_load_addr;

	u64 cr3_target_value0;
	u64 cr3_target_value1;
	u64 cr3_target_value2;
	u64 cr3_target_value3;

	u32 page_fault_error_code_mask;
	u32 page_fault_error_code_match;

	u32 cr3_target_count;
	u32 vm_exit_msr_store_count;
	u32 vm_exit_msr_load_count;
	u32 vm_entry_msr_load_count;

	u64 tsc_offset;
	u64 virtual_apic_page_addr;
	u64 vmcs_link_pointer;

	u64 guest_ia32_debugctl;
	u64 guest_ia32_pat;
	u64 guest_ia32_efer;

	u64 guest_pdptr0;
	u64 guest_pdptr1;
	u64 guest_pdptr2;
	u64 guest_pdptr3;

	u64 guest_pending_dbg_exceptions;
	u64 guest_sysenter_esp;
	u64 guest_sysenter_eip;

	u32 guest_activity_state;
	u32 guest_sysenter_cs;

	u64 cr0_guest_host_mask;
	u64 cr4_guest_host_mask;
	u64 cr0_read_shadow;
	u64 cr4_read_shadow;
	u64 guest_cr0;
	u64 guest_cr3;
	u64 guest_cr4;
	u64 guest_dr7;

	u64 host_fs_base;
	u64 host_gs_base;
	u64 host_tr_base;
	u64 host_gdtr_base;
	u64 host_idtr_base;
	u64 host_rsp;

	u64 ept_pointer;

	u16 virtual_processor_id;
	u16 padding16_2[3];

	u64 padding64_2[5];
	u64 guest_physical_address;

	u32 vm_instruction_error;
	u32 vm_exit_reason;
	u32 vm_exit_intr_info;
	u32 vm_exit_intr_error_code;
	u32 idt_vectoring_info_field;
	u32 idt_vectoring_error_code;
	u32 vm_exit_instruction_len;
	u32 vmx_instruction_info;

	u64 exit_qualification;
	u64 exit_io_instruction_ecx;
	u64 exit_io_instruction_esi;
	u64 exit_io_instruction_edi;
	u64 exit_io_instruction_eip;

	u64 guest_linear_address;
	u64 guest_rsp;
	u64 guest_rflags;

	u32 guest_interruptibility_info;
	u32 cpu_based_vm_exec_control;
	u32 exception_bitmap;
	u32 vm_entry_controls;
	u32 vm_entry_intr_info_field;
	u32 vm_entry_exception_error_code;
	u32 vm_entry_instruction_len;
	u32 tpr_threshold;

	u64 guest_rip;

	u32 hv_clean_fields;
	u32 padding32_1;
	u32 hv_synthetic_controls;
	struct {
		u32 nested_flush_hypercall:1;
		u32 msr_bitmap:1;
		u32 reserved:30;
	}  __packed hv_enlightenments_control;
	u32 hv_vp_id;
	u32 padding32_2;
	u64 hv_vm_id;
	u64 partition_assist_page;
	u64 padding64_4[4];
	u64 guest_bndcfgs;
	u64 guest_ia32_perf_global_ctrl;
	u64 guest_ia32_s_cet;
	u64 guest_ssp;
	u64 guest_ia32_int_ssp_table_addr;
	u64 guest_ia32_lbr_ctl;
	u64 padding64_5[2];
	u64 xss_exit_bitmap;
	u64 encls_exiting_bitmap;
	u64 host_ia32_perf_global_ctrl;
	u64 tsc_multiplier;
	u64 host_ia32_s_cet;
	u64 host_ssp;
	u64 host_ia32_int_ssp_table_addr;
	u64 padding64_6;
} __packed;

#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE                     0
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_IO_BITMAP                BIT(0)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_MSR_BITMAP               BIT(1)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP2             BIT(2)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP1             BIT(3)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_PROC             BIT(4)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_EVENT            BIT(5)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_ENTRY            BIT(6)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_EXCPN            BIT(7)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR                     BIT(8)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_XLAT             BIT(9)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_BASIC              BIT(10)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1               BIT(11)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2               BIT(12)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_POINTER             BIT(13)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1                BIT(14)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_ENLIGHTENMENTSCONTROL    BIT(15)
#define HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL                      0xFFFF

#define HV_VMX_SYNTHETIC_EXIT_REASON_TRAP_AFTER_FLUSH 0x10000031

extern struct hv_enlightened_vmcs *current_evmcs;

int vcpu_enable_evmcs(struct kvm_vcpu *vcpu);

static inline void evmcs_enable(void)
{
	enable_evmcs = true;
}

static inline int evmcs_vmptrld(uint64_t vmcs_pa, void *vmcs)
{
	current_vp_assist->current_nested_vmcs = vmcs_pa;
	current_vp_assist->enlighten_vmentry = 1;

	current_evmcs = vmcs;

	return 0;
}

static inline bool load_evmcs(struct hyperv_test_pages *hv)
{
	if (evmcs_vmptrld(hv->enlightened_vmcs_gpa, hv->enlightened_vmcs))
		return false;

	current_evmcs->revision_id = EVMCS_VERSION;

	return true;
}

static inline int evmcs_vmptrst(uint64_t *value)
{
	*value = current_vp_assist->current_nested_vmcs &
		~HV_X64_MSR_VP_ASSIST_PAGE_ENABLE;

	return 0;
}

static inline int evmcs_vmread(uint64_t encoding, uint64_t *value)
{
	switch (encoding) {
	case GUEST_RIP:
		*value = current_evmcs->guest_rip;
		break;
	case GUEST_RSP:
		*value = current_evmcs->guest_rsp;
		break;
	case GUEST_RFLAGS:
		*value = current_evmcs->guest_rflags;
		break;
	case HOST_IA32_PAT:
		*value = current_evmcs->host_ia32_pat;
		break;
	case HOST_IA32_EFER:
		*value = current_evmcs->host_ia32_efer;
		break;
	case HOST_CR0:
		*value = current_evmcs->host_cr0;
		break;
	case HOST_CR3:
		*value = current_evmcs->host_cr3;
		break;
	case HOST_CR4:
		*value = current_evmcs->host_cr4;
		break;
	case HOST_IA32_SYSENTER_ESP:
		*value = current_evmcs->host_ia32_sysenter_esp;
		break;
	case HOST_IA32_SYSENTER_EIP:
		*value = current_evmcs->host_ia32_sysenter_eip;
		break;
	case HOST_RIP:
		*value = current_evmcs->host_rip;
		break;
	case IO_BITMAP_A:
		*value = current_evmcs->io_bitmap_a;
		break;
	case IO_BITMAP_B:
		*value = current_evmcs->io_bitmap_b;
		break;
	case MSR_BITMAP:
		*value = current_evmcs->msr_bitmap;
		break;
	case GUEST_ES_BASE:
		*value = current_evmcs->guest_es_base;
		break;
	case GUEST_CS_BASE:
		*value = current_evmcs->guest_cs_base;
		break;
	case GUEST_SS_BASE:
		*value = current_evmcs->guest_ss_base;
		break;
	case GUEST_DS_BASE:
		*value = current_evmcs->guest_ds_base;
		break;
	case GUEST_FS_BASE:
		*value = current_evmcs->guest_fs_base;
		break;
	case GUEST_GS_BASE:
		*value = current_evmcs->guest_gs_base;
		break;
	case GUEST_LDTR_BASE:
		*value = current_evmcs->guest_ldtr_base;
		break;
	case GUEST_TR_BASE:
		*value = current_evmcs->guest_tr_base;
		break;
	case GUEST_GDTR_BASE:
		*value = current_evmcs->guest_gdtr_base;
		break;
	case GUEST_IDTR_BASE:
		*value = current_evmcs->guest_idtr_base;
		break;
	case TSC_OFFSET:
		*value = current_evmcs->tsc_offset;
		break;
	case VIRTUAL_APIC_PAGE_ADDR:
		*value = current_evmcs->virtual_apic_page_addr;
		break;
	case VMCS_LINK_POINTER:
		*value = current_evmcs->vmcs_link_pointer;
		break;
	case GUEST_IA32_DEBUGCTL:
		*value = current_evmcs->guest_ia32_debugctl;
		break;
	case GUEST_IA32_PAT:
		*value = current_evmcs->guest_ia32_pat;
		break;
	case GUEST_IA32_EFER:
		*value = current_evmcs->guest_ia32_efer;
		break;
	case GUEST_PDPTR0:
		*value = current_evmcs->guest_pdptr0;
		break;
	case GUEST_PDPTR1:
		*value = current_evmcs->guest_pdptr1;
		break;
	case GUEST_PDPTR2:
		*value = current_evmcs->guest_pdptr2;
		break;
	case GUEST_PDPTR3:
		*value = current_evmcs->guest_pdptr3;
		break;
	case GUEST_PENDING_DBG_EXCEPTIONS:
		*value = current_evmcs->guest_pending_dbg_exceptions;
		break;
	case GUEST_SYSENTER_ESP:
		*value = current_evmcs->guest_sysenter_esp;
		break;
	case GUEST_SYSENTER_EIP:
		*value = current_evmcs->guest_sysenter_eip;
		break;
	case CR0_GUEST_HOST_MASK:
		*value = current_evmcs->cr0_guest_host_mask;
		break;
	case CR4_GUEST_HOST_MASK:
		*value = current_evmcs->cr4_guest_host_mask;
		break;
	case CR0_READ_SHADOW:
		*value = current_evmcs->cr0_read_shadow;
		break;
	case CR4_READ_SHADOW:
		*value = current_evmcs->cr4_read_shadow;
		break;
	case GUEST_CR0:
		*value = current_evmcs->guest_cr0;
		break;
	case GUEST_CR3:
		*value = current_evmcs->guest_cr3;
		break;
	case GUEST_CR4:
		*value = current_evmcs->guest_cr4;
		break;
	case GUEST_DR7:
		*value = current_evmcs->guest_dr7;
		break;
	case HOST_FS_BASE:
		*value = current_evmcs->host_fs_base;
		break;
	case HOST_GS_BASE:
		*value = current_evmcs->host_gs_base;
		break;
	case HOST_TR_BASE:
		*value = current_evmcs->host_tr_base;
		break;
	case HOST_GDTR_BASE:
		*value = current_evmcs->host_gdtr_base;
		break;
	case HOST_IDTR_BASE:
		*value = current_evmcs->host_idtr_base;
		break;
	case HOST_RSP:
		*value = current_evmcs->host_rsp;
		break;
	case EPT_POINTER:
		*value = current_evmcs->ept_pointer;
		break;
	case GUEST_BNDCFGS:
		*value = current_evmcs->guest_bndcfgs;
		break;
	case XSS_EXIT_BITMAP:
		*value = current_evmcs->xss_exit_bitmap;
		break;
	case GUEST_PHYSICAL_ADDRESS:
		*value = current_evmcs->guest_physical_address;
		break;
	case EXIT_QUALIFICATION:
		*value = current_evmcs->exit_qualification;
		break;
	case GUEST_LINEAR_ADDRESS:
		*value = current_evmcs->guest_linear_address;
		break;
	case VM_EXIT_MSR_STORE_ADDR:
		*value = current_evmcs->vm_exit_msr_store_addr;
		break;
	case VM_EXIT_MSR_LOAD_ADDR:
		*value = current_evmcs->vm_exit_msr_load_addr;
		break;
	case VM_ENTRY_MSR_LOAD_ADDR:
		*value = current_evmcs->vm_entry_msr_load_addr;
		break;
	case CR3_TARGET_VALUE0:
		*value = current_evmcs->cr3_target_value0;
		break;
	case CR3_TARGET_VALUE1:
		*value = current_evmcs->cr3_target_value1;
		break;
	case CR3_TARGET_VALUE2:
		*value = current_evmcs->cr3_target_value2;
		break;
	case CR3_TARGET_VALUE3:
		*value = current_evmcs->cr3_target_value3;
		break;
	case TPR_THRESHOLD:
		*value = current_evmcs->tpr_threshold;
		break;
	case GUEST_INTERRUPTIBILITY_INFO:
		*value = current_evmcs->guest_interruptibility_info;
		break;
	case CPU_BASED_VM_EXEC_CONTROL:
		*value = current_evmcs->cpu_based_vm_exec_control;
		break;
	case EXCEPTION_BITMAP:
		*value = current_evmcs->exception_bitmap;
		break;
	case VM_ENTRY_CONTROLS:
		*value = current_evmcs->vm_entry_controls;
		break;
	case VM_ENTRY_INTR_INFO_FIELD:
		*value = current_evmcs->vm_entry_intr_info_field;
		break;
	case VM_ENTRY_EXCEPTION_ERROR_CODE:
		*value = current_evmcs->vm_entry_exception_error_code;
		break;
	case VM_ENTRY_INSTRUCTION_LEN:
		*value = current_evmcs->vm_entry_instruction_len;
		break;
	case HOST_IA32_SYSENTER_CS:
		*value = current_evmcs->host_ia32_sysenter_cs;
		break;
	case PIN_BASED_VM_EXEC_CONTROL:
		*value = current_evmcs->pin_based_vm_exec_control;
		break;
	case VM_EXIT_CONTROLS:
		*value = current_evmcs->vm_exit_controls;
		break;
	case SECONDARY_VM_EXEC_CONTROL:
		*value = current_evmcs->secondary_vm_exec_control;
		break;
	case GUEST_ES_LIMIT:
		*value = current_evmcs->guest_es_limit;
		break;
	case GUEST_CS_LIMIT:
		*value = current_evmcs->guest_cs_limit;
		break;
	case GUEST_SS_LIMIT:
		*value = current_evmcs->guest_ss_limit;
		break;
	case GUEST_DS_LIMIT:
		*value = current_evmcs->guest_ds_limit;
		break;
	case GUEST_FS_LIMIT:
		*value = current_evmcs->guest_fs_limit;
		break;
	case GUEST_GS_LIMIT:
		*value = current_evmcs->guest_gs_limit;
		break;
	case GUEST_LDTR_LIMIT:
		*value = current_evmcs->guest_ldtr_limit;
		break;
	case GUEST_TR_LIMIT:
		*value = current_evmcs->guest_tr_limit;
		break;
	case GUEST_GDTR_LIMIT:
		*value = current_evmcs->guest_gdtr_limit;
		break;
	case GUEST_IDTR_LIMIT:
		*value = current_evmcs->guest_idtr_limit;
		break;
	case GUEST_ES_AR_BYTES:
		*value = current_evmcs->guest_es_ar_bytes;
		break;
	case GUEST_CS_AR_BYTES:
		*value = current_evmcs->guest_cs_ar_bytes;
		break;
	case GUEST_SS_AR_BYTES:
		*value = current_evmcs->guest_ss_ar_bytes;
		break;
	case GUEST_DS_AR_BYTES:
		*value = current_evmcs->guest_ds_ar_bytes;
		break;
	case GUEST_FS_AR_BYTES:
		*value = current_evmcs->guest_fs_ar_bytes;
		break;
	case GUEST_GS_AR_BYTES:
		*value = current_evmcs->guest_gs_ar_bytes;
		break;
	case GUEST_LDTR_AR_BYTES:
		*value = current_evmcs->guest_ldtr_ar_bytes;
		break;
	case GUEST_TR_AR_BYTES:
		*value = current_evmcs->guest_tr_ar_bytes;
		break;
	case GUEST_ACTIVITY_STATE:
		*value = current_evmcs->guest_activity_state;
		break;
	case GUEST_SYSENTER_CS:
		*value = current_evmcs->guest_sysenter_cs;
		break;
	case VM_INSTRUCTION_ERROR:
		*value = current_evmcs->vm_instruction_error;
		break;
	case VM_EXIT_REASON:
		*value = current_evmcs->vm_exit_reason;
		break;
	case VM_EXIT_INTR_INFO:
		*value = current_evmcs->vm_exit_intr_info;
		break;
	case VM_EXIT_INTR_ERROR_CODE:
		*value = current_evmcs->vm_exit_intr_error_code;
		break;
	case IDT_VECTORING_INFO_FIELD:
		*value = current_evmcs->idt_vectoring_info_field;
		break;
	case IDT_VECTORING_ERROR_CODE:
		*value = current_evmcs->idt_vectoring_error_code;
		break;
	case VM_EXIT_INSTRUCTION_LEN:
		*value = current_evmcs->vm_exit_instruction_len;
		break;
	case VMX_INSTRUCTION_INFO:
		*value = current_evmcs->vmx_instruction_info;
		break;
	case PAGE_FAULT_ERROR_CODE_MASK:
		*value = current_evmcs->page_fault_error_code_mask;
		break;
	case PAGE_FAULT_ERROR_CODE_MATCH:
		*value = current_evmcs->page_fault_error_code_match;
		break;
	case CR3_TARGET_COUNT:
		*value = current_evmcs->cr3_target_count;
		break;
	case VM_EXIT_MSR_STORE_COUNT:
		*value = current_evmcs->vm_exit_msr_store_count;
		break;
	case VM_EXIT_MSR_LOAD_COUNT:
		*value = current_evmcs->vm_exit_msr_load_count;
		break;
	case VM_ENTRY_MSR_LOAD_COUNT:
		*value = current_evmcs->vm_entry_msr_load_count;
		break;
	case HOST_ES_SELECTOR:
		*value = current_evmcs->host_es_selector;
		break;
	case HOST_CS_SELECTOR:
		*value = current_evmcs->host_cs_selector;
		break;
	case HOST_SS_SELECTOR:
		*value = current_evmcs->host_ss_selector;
		break;
	case HOST_DS_SELECTOR:
		*value = current_evmcs->host_ds_selector;
		break;
	case HOST_FS_SELECTOR:
		*value = current_evmcs->host_fs_selector;
		break;
	case HOST_GS_SELECTOR:
		*value = current_evmcs->host_gs_selector;
		break;
	case HOST_TR_SELECTOR:
		*value = current_evmcs->host_tr_selector;
		break;
	case GUEST_ES_SELECTOR:
		*value = current_evmcs->guest_es_selector;
		break;
	case GUEST_CS_SELECTOR:
		*value = current_evmcs->guest_cs_selector;
		break;
	case GUEST_SS_SELECTOR:
		*value = current_evmcs->guest_ss_selector;
		break;
	case GUEST_DS_SELECTOR:
		*value = current_evmcs->guest_ds_selector;
		break;
	case GUEST_FS_SELECTOR:
		*value = current_evmcs->guest_fs_selector;
		break;
	case GUEST_GS_SELECTOR:
		*value = current_evmcs->guest_gs_selector;
		break;
	case GUEST_LDTR_SELECTOR:
		*value = current_evmcs->guest_ldtr_selector;
		break;
	case GUEST_TR_SELECTOR:
		*value = current_evmcs->guest_tr_selector;
		break;
	case VIRTUAL_PROCESSOR_ID:
		*value = current_evmcs->virtual_processor_id;
		break;
	case HOST_IA32_PERF_GLOBAL_CTRL:
		*value = current_evmcs->host_ia32_perf_global_ctrl;
		break;
	case GUEST_IA32_PERF_GLOBAL_CTRL:
		*value = current_evmcs->guest_ia32_perf_global_ctrl;
		break;
	case ENCLS_EXITING_BITMAP:
		*value = current_evmcs->encls_exiting_bitmap;
		break;
	case TSC_MULTIPLIER:
		*value = current_evmcs->tsc_multiplier;
		break;
	default: return 1;
	}

	return 0;
}

static inline int evmcs_vmwrite(uint64_t encoding, uint64_t value)
{
	switch (encoding) {
	case GUEST_RIP:
		current_evmcs->guest_rip = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case GUEST_RSP:
		current_evmcs->guest_rsp = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_BASIC;
		break;
	case GUEST_RFLAGS:
		current_evmcs->guest_rflags = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_BASIC;
		break;
	case HOST_IA32_PAT:
		current_evmcs->host_ia32_pat = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_IA32_EFER:
		current_evmcs->host_ia32_efer = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_CR0:
		current_evmcs->host_cr0 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_CR3:
		current_evmcs->host_cr3 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_CR4:
		current_evmcs->host_cr4 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_IA32_SYSENTER_ESP:
		current_evmcs->host_ia32_sysenter_esp = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_IA32_SYSENTER_EIP:
		current_evmcs->host_ia32_sysenter_eip = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_RIP:
		current_evmcs->host_rip = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case IO_BITMAP_A:
		current_evmcs->io_bitmap_a = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_IO_BITMAP;
		break;
	case IO_BITMAP_B:
		current_evmcs->io_bitmap_b = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_IO_BITMAP;
		break;
	case MSR_BITMAP:
		current_evmcs->msr_bitmap = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_MSR_BITMAP;
		break;
	case GUEST_ES_BASE:
		current_evmcs->guest_es_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_CS_BASE:
		current_evmcs->guest_cs_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_SS_BASE:
		current_evmcs->guest_ss_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_DS_BASE:
		current_evmcs->guest_ds_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_FS_BASE:
		current_evmcs->guest_fs_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_GS_BASE:
		current_evmcs->guest_gs_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_LDTR_BASE:
		current_evmcs->guest_ldtr_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_TR_BASE:
		current_evmcs->guest_tr_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_GDTR_BASE:
		current_evmcs->guest_gdtr_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_IDTR_BASE:
		current_evmcs->guest_idtr_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case TSC_OFFSET:
		current_evmcs->tsc_offset = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP2;
		break;
	case VIRTUAL_APIC_PAGE_ADDR:
		current_evmcs->virtual_apic_page_addr = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP2;
		break;
	case VMCS_LINK_POINTER:
		current_evmcs->vmcs_link_pointer = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_IA32_DEBUGCTL:
		current_evmcs->guest_ia32_debugctl = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_IA32_PAT:
		current_evmcs->guest_ia32_pat = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_IA32_EFER:
		current_evmcs->guest_ia32_efer = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_PDPTR0:
		current_evmcs->guest_pdptr0 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_PDPTR1:
		current_evmcs->guest_pdptr1 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_PDPTR2:
		current_evmcs->guest_pdptr2 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_PDPTR3:
		current_evmcs->guest_pdptr3 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_PENDING_DBG_EXCEPTIONS:
		current_evmcs->guest_pending_dbg_exceptions = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_SYSENTER_ESP:
		current_evmcs->guest_sysenter_esp = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_SYSENTER_EIP:
		current_evmcs->guest_sysenter_eip = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case CR0_GUEST_HOST_MASK:
		current_evmcs->cr0_guest_host_mask = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR;
		break;
	case CR4_GUEST_HOST_MASK:
		current_evmcs->cr4_guest_host_mask = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR;
		break;
	case CR0_READ_SHADOW:
		current_evmcs->cr0_read_shadow = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR;
		break;
	case CR4_READ_SHADOW:
		current_evmcs->cr4_read_shadow = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR;
		break;
	case GUEST_CR0:
		current_evmcs->guest_cr0 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR;
		break;
	case GUEST_CR3:
		current_evmcs->guest_cr3 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR;
		break;
	case GUEST_CR4:
		current_evmcs->guest_cr4 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR;
		break;
	case GUEST_DR7:
		current_evmcs->guest_dr7 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CRDR;
		break;
	case HOST_FS_BASE:
		current_evmcs->host_fs_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_POINTER;
		break;
	case HOST_GS_BASE:
		current_evmcs->host_gs_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_POINTER;
		break;
	case HOST_TR_BASE:
		current_evmcs->host_tr_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_POINTER;
		break;
	case HOST_GDTR_BASE:
		current_evmcs->host_gdtr_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_POINTER;
		break;
	case HOST_IDTR_BASE:
		current_evmcs->host_idtr_base = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_POINTER;
		break;
	case HOST_RSP:
		current_evmcs->host_rsp = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_POINTER;
		break;
	case EPT_POINTER:
		current_evmcs->ept_pointer = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_XLAT;
		break;
	case GUEST_BNDCFGS:
		current_evmcs->guest_bndcfgs = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case XSS_EXIT_BITMAP:
		current_evmcs->xss_exit_bitmap = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP2;
		break;
	case GUEST_PHYSICAL_ADDRESS:
		current_evmcs->guest_physical_address = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case EXIT_QUALIFICATION:
		current_evmcs->exit_qualification = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case GUEST_LINEAR_ADDRESS:
		current_evmcs->guest_linear_address = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case VM_EXIT_MSR_STORE_ADDR:
		current_evmcs->vm_exit_msr_store_addr = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case VM_EXIT_MSR_LOAD_ADDR:
		current_evmcs->vm_exit_msr_load_addr = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case VM_ENTRY_MSR_LOAD_ADDR:
		current_evmcs->vm_entry_msr_load_addr = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case CR3_TARGET_VALUE0:
		current_evmcs->cr3_target_value0 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case CR3_TARGET_VALUE1:
		current_evmcs->cr3_target_value1 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case CR3_TARGET_VALUE2:
		current_evmcs->cr3_target_value2 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case CR3_TARGET_VALUE3:
		current_evmcs->cr3_target_value3 = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case TPR_THRESHOLD:
		current_evmcs->tpr_threshold = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case GUEST_INTERRUPTIBILITY_INFO:
		current_evmcs->guest_interruptibility_info = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_BASIC;
		break;
	case CPU_BASED_VM_EXEC_CONTROL:
		current_evmcs->cpu_based_vm_exec_control = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_PROC;
		break;
	case EXCEPTION_BITMAP:
		current_evmcs->exception_bitmap = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_EXCPN;
		break;
	case VM_ENTRY_CONTROLS:
		current_evmcs->vm_entry_controls = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_ENTRY;
		break;
	case VM_ENTRY_INTR_INFO_FIELD:
		current_evmcs->vm_entry_intr_info_field = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_EVENT;
		break;
	case VM_ENTRY_EXCEPTION_ERROR_CODE:
		current_evmcs->vm_entry_exception_error_code = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_EVENT;
		break;
	case VM_ENTRY_INSTRUCTION_LEN:
		current_evmcs->vm_entry_instruction_len = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_EVENT;
		break;
	case HOST_IA32_SYSENTER_CS:
		current_evmcs->host_ia32_sysenter_cs = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case PIN_BASED_VM_EXEC_CONTROL:
		current_evmcs->pin_based_vm_exec_control = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP1;
		break;
	case VM_EXIT_CONTROLS:
		current_evmcs->vm_exit_controls = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP1;
		break;
	case SECONDARY_VM_EXEC_CONTROL:
		current_evmcs->secondary_vm_exec_control = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP1;
		break;
	case GUEST_ES_LIMIT:
		current_evmcs->guest_es_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_CS_LIMIT:
		current_evmcs->guest_cs_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_SS_LIMIT:
		current_evmcs->guest_ss_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_DS_LIMIT:
		current_evmcs->guest_ds_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_FS_LIMIT:
		current_evmcs->guest_fs_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_GS_LIMIT:
		current_evmcs->guest_gs_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_LDTR_LIMIT:
		current_evmcs->guest_ldtr_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_TR_LIMIT:
		current_evmcs->guest_tr_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_GDTR_LIMIT:
		current_evmcs->guest_gdtr_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_IDTR_LIMIT:
		current_evmcs->guest_idtr_limit = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_ES_AR_BYTES:
		current_evmcs->guest_es_ar_bytes = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_CS_AR_BYTES:
		current_evmcs->guest_cs_ar_bytes = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_SS_AR_BYTES:
		current_evmcs->guest_ss_ar_bytes = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_DS_AR_BYTES:
		current_evmcs->guest_ds_ar_bytes = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_FS_AR_BYTES:
		current_evmcs->guest_fs_ar_bytes = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_GS_AR_BYTES:
		current_evmcs->guest_gs_ar_bytes = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_LDTR_AR_BYTES:
		current_evmcs->guest_ldtr_ar_bytes = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_TR_AR_BYTES:
		current_evmcs->guest_tr_ar_bytes = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_ACTIVITY_STATE:
		current_evmcs->guest_activity_state = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case GUEST_SYSENTER_CS:
		current_evmcs->guest_sysenter_cs = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case VM_INSTRUCTION_ERROR:
		current_evmcs->vm_instruction_error = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case VM_EXIT_REASON:
		current_evmcs->vm_exit_reason = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case VM_EXIT_INTR_INFO:
		current_evmcs->vm_exit_intr_info = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case VM_EXIT_INTR_ERROR_CODE:
		current_evmcs->vm_exit_intr_error_code = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case IDT_VECTORING_INFO_FIELD:
		current_evmcs->idt_vectoring_info_field = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case IDT_VECTORING_ERROR_CODE:
		current_evmcs->idt_vectoring_error_code = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case VM_EXIT_INSTRUCTION_LEN:
		current_evmcs->vm_exit_instruction_len = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case VMX_INSTRUCTION_INFO:
		current_evmcs->vmx_instruction_info = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_NONE;
		break;
	case PAGE_FAULT_ERROR_CODE_MASK:
		current_evmcs->page_fault_error_code_mask = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case PAGE_FAULT_ERROR_CODE_MATCH:
		current_evmcs->page_fault_error_code_match = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case CR3_TARGET_COUNT:
		current_evmcs->cr3_target_count = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case VM_EXIT_MSR_STORE_COUNT:
		current_evmcs->vm_exit_msr_store_count = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case VM_EXIT_MSR_LOAD_COUNT:
		current_evmcs->vm_exit_msr_load_count = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case VM_ENTRY_MSR_LOAD_COUNT:
		current_evmcs->vm_entry_msr_load_count = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_ALL;
		break;
	case HOST_ES_SELECTOR:
		current_evmcs->host_es_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_CS_SELECTOR:
		current_evmcs->host_cs_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_SS_SELECTOR:
		current_evmcs->host_ss_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_DS_SELECTOR:
		current_evmcs->host_ds_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_FS_SELECTOR:
		current_evmcs->host_fs_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_GS_SELECTOR:
		current_evmcs->host_gs_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case HOST_TR_SELECTOR:
		current_evmcs->host_tr_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case GUEST_ES_SELECTOR:
		current_evmcs->guest_es_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_CS_SELECTOR:
		current_evmcs->guest_cs_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_SS_SELECTOR:
		current_evmcs->guest_ss_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_DS_SELECTOR:
		current_evmcs->guest_ds_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_FS_SELECTOR:
		current_evmcs->guest_fs_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_GS_SELECTOR:
		current_evmcs->guest_gs_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_LDTR_SELECTOR:
		current_evmcs->guest_ldtr_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case GUEST_TR_SELECTOR:
		current_evmcs->guest_tr_selector = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP2;
		break;
	case VIRTUAL_PROCESSOR_ID:
		current_evmcs->virtual_processor_id = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_XLAT;
		break;
	case HOST_IA32_PERF_GLOBAL_CTRL:
		current_evmcs->host_ia32_perf_global_ctrl = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
		break;
	case GUEST_IA32_PERF_GLOBAL_CTRL:
		current_evmcs->guest_ia32_perf_global_ctrl = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_GUEST_GRP1;
		break;
	case ENCLS_EXITING_BITMAP:
		current_evmcs->encls_exiting_bitmap = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP2;
		break;
	case TSC_MULTIPLIER:
		current_evmcs->tsc_multiplier = value;
		current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_CONTROL_GRP2;
		break;
	default: return 1;
	}

	return 0;
}

static inline int evmcs_vmlaunch(void)
{
	int ret;

	current_evmcs->hv_clean_fields = 0;

	__asm__ __volatile__("push %%rbp;"
			     "push %%rcx;"
			     "push %%rdx;"
			     "push %%rsi;"
			     "push %%rdi;"
			     "push $0;"
			     "mov %%rsp, (%[host_rsp]);"
			     "lea 1f(%%rip), %%rax;"
			     "mov %%rax, (%[host_rip]);"
			     "vmlaunch;"
			     "incq (%%rsp);"
			     "1: pop %%rax;"
			     "pop %%rdi;"
			     "pop %%rsi;"
			     "pop %%rdx;"
			     "pop %%rcx;"
			     "pop %%rbp;"
			     : [ret]"=&a"(ret)
			     : [host_rsp]"r"
			       ((uint64_t)&current_evmcs->host_rsp),
			       [host_rip]"r"
			       ((uint64_t)&current_evmcs->host_rip)
			     : "memory", "cc", "rbx", "r8", "r9", "r10",
			       "r11", "r12", "r13", "r14", "r15");
	return ret;
}

/*
 * No guest state (e.g. GPRs) is established by this vmresume.
 */
static inline int evmcs_vmresume(void)
{
	int ret;

	/* HOST_RIP */
	current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_GRP1;
	/* HOST_RSP */
	current_evmcs->hv_clean_fields &= ~HV_VMX_ENLIGHTENED_CLEAN_FIELD_HOST_POINTER;

	__asm__ __volatile__("push %%rbp;"
			     "push %%rcx;"
			     "push %%rdx;"
			     "push %%rsi;"
			     "push %%rdi;"
			     "push $0;"
			     "mov %%rsp, (%[host_rsp]);"
			     "lea 1f(%%rip), %%rax;"
			     "mov %%rax, (%[host_rip]);"
			     "vmresume;"
			     "incq (%%rsp);"
			     "1: pop %%rax;"
			     "pop %%rdi;"
			     "pop %%rsi;"
			     "pop %%rdx;"
			     "pop %%rcx;"
			     "pop %%rbp;"
			     : [ret]"=&a"(ret)
			     : [host_rsp]"r"
			       ((uint64_t)&current_evmcs->host_rsp),
			       [host_rip]"r"
			       ((uint64_t)&current_evmcs->host_rip)
			     : "memory", "cc", "rbx", "r8", "r9", "r10",
			       "r11", "r12", "r13", "r14", "r15");
	return ret;
}

#endif /* !SELFTEST_KVM_EVMCS_H */
